
{
	fftwf_complex *inFreqTmp; // tmp decimation output buffers (after tune shift)

	const int decimate = this->mdecimation;
	const int mfft = this->mfftdim[decimate]; // = halfFft / 2^mdecimation
	const fftwf_complex *filter = filterHw[decimate];
	const bool lsb = this->getSideband();
	const auto filter2 = &filter[halfFft - mfft / 2];

	inFreqTmp = (fftwf_complex *)fftwf_malloc(sizeof(fftwf_complex) * (halfFft)); // 1024
	fftwf_plan plan_f2t_c2c = fftwf_plan_dft_1d(mfftdim[decimate], inFreqTmp, inFreqTmp, FFTW_BACKWARD, FFTW_MEASURE);

	int decimate_count = 0;
	fftwf_complex *pout = nullptr;

	while (r2iqOn)
	{
		const int16_t *dataADC; // pointer to input data
		const int16_t *endloop; // pointer to end data to be copied to beginning

		const int _mtunebin = this->mtunebin; // Update LO tune is possible during run

		dataADC = inputbuffer->getReadPtr();

		if (!r2iqOn)
			return 0;

		this->bufIdx = (this->bufIdx + 1) % QUEUE_SIZE;

		endloop = inputbuffer->peekReadPtr(-1) + transferSamples - halfFft;

		auto inloop = this->ADCinTime;

		// @todo: move the following int16_t conversion to (32-bit) float
		// directly inside the following loop (for "k < fftPerBuf")
		//   just before the forward fft "fftwf_execute_dft_r2c" is called
		// idea: this should improve cache/memory locality
#if PRINT_INPUT_RANGE
		std::pair<int16_t, int16_t> blockMinMax = std::make_pair<int16_t, int16_t>(0, 0);
#endif
		if (!this->getRand()) // plain samples no ADC rand set
		{
			convert_float<false>(endloop, inloop, halfFft);
#if PRINT_INPUT_RANGE
			auto minmax = std::minmax_element(dataADC, dataADC + transferSamples);
			blockMinMax.first = *minmax.first;
			blockMinMax.second = *minmax.second;
#endif
			convert_float<false>(dataADC, inloop + halfFft, transferSamples);
		}
		else
		{
			convert_float<true>(endloop, inloop, halfFft);
			convert_float<true>(dataADC, inloop + halfFft, transferSamples);
		}

#if PRINT_INPUT_RANGE
		this->MinValue = std::min(blockMinMax.first, this->MinValue);
		this->MaxValue = std::max(blockMinMax.second, this->MaxValue);
		++this->MinMaxBlockCount;
		if (this->MinMaxBlockCount * processor_count / 3 >= DEFAULT_TRANSFERS_PER_SEC)
		{
			float minBits = (this->MinValue < 0) ? (log10f((float)(-this->MinValue)) / log10f(2.0f)) : -1.0f;
			float maxBits = (this->MaxValue > 0) ? (log10f((float)(this->MaxValue)) / log10f(2.0f)) : -1.0f;
			printf("r2iq: min = %d (%.1f bits) %.2f%%, max = %d (%.1f bits) %.2f%%\n",
				   (int)this->MinValue, minBits, this->MinValue * -100.0f / 32768.0f,
				   (int)this->MaxValue, maxBits, this->MaxValue * 100.0f / 32768.0f);
			this->MinValue = 0;
			this->MaxValue = 0;
			this->MinMaxBlockCount = 0;
		}
#endif
		dataADC = nullptr;
		inputbuffer->ReadDone();
		// decimate in frequency plus tuning

		if (decimate_count == 0)
			pout = (fftwf_complex *)outputbuffer->getWritePtr();

		decimate_count = (decimate_count + 1) & ((1 << decimate) - 1);

		// Calculate the parameters for the first half
		const auto count = std::min(mfft / 2, halfFft - _mtunebin);
		const auto source = &this->ADCinFreq[_mtunebin];

		// Calculate the parameters for the second half
		const auto start = std::max(0, mfft / 2 - _mtunebin);
		const auto source2 = &this->ADCinFreq[_mtunebin - mfft / 2];
		const auto dest = &inFreqTmp[mfft / 2];
		for (int k = 0; k < fftPerBuf; k++)
		{
			// core of fast convolution including filter and decimation
			//   main part is 'overlap-scrap' (IMHO better name for 'overlap-save'), see
			//   https://en.wikipedia.org/wiki/Overlap%E2%80%93save_method
			{
				// FFT first stage: time to frequency, real to complex
				// 'full' transformation size: 2 * halfFft
				fftwf_execute_dft_r2c(plan_t2f_r2c, this->ADCinTime + (3 * halfFft / 2) * k, this->ADCinFreq);
				// result now in this->ADCinFreq[]

				// circular shift (mixing in full bins) and low/bandpass filtering (complex multiplication)
				{
					// circular shift tune fs/2 first half array into inFreqTmp[]
					shift_freq(inFreqTmp, source, filter, 0, count);
					if (mfft / 2 != count)
						memset(inFreqTmp[count], 0, sizeof(float) * 2 * (mfft / 2 - count));

					// circular shift tune fs/2 second half array
					shift_freq(dest, source2, filter2, start, mfft / 2);
					if (start != 0)
						memset(inFreqTmp[mfft / 2], 0, sizeof(float) * 2 * start);
				}
				// result now in inFreqTmp[]

				// 'shorter' inverse FFT transform (decimation); frequency (back) to COMPLEX time domain
				// transform size: mfft = mfftdim[k] = halfFft / 2^k with k = mdecimation
				fftwf_execute_dft(plan_f2t_c2c, inFreqTmp, inFreqTmp); //  c2c decimation
																	   // result now in inFreqTmp[]
			}

			// postprocessing
			// @todo: is it possible to ..
			//  1)
			//    let inverse FFT produce/save it's result directly
			//    in "this->obuffers[modx] + offset" (pout)
			//    ( obuffers[] would need to have additional space ..;
			//      need to move 'scrap' of 'ovelap-scrap'? )
			//    at least FFTW would allow so,
			//      see http://www.fftw.org/fftw3_doc/New_002darray-Execute-Functions.html
			//    attention: multithreading!
			//  2)
			//    could mirroring (lower sideband) get calculated together
			//    with fine mixer - modifying the mixer frequency? (fs - fc)/fs
			//    (this would reduce one memory pass)
			if (lsb) // lower sideband
			{
				// mirror just by negating the imaginary Q of complex I/Q
				if (k == 0)
				{
					copy<true>(pout, &inFreqTmp[mfft / 4], mfft / 2);
				}
				else
				{
					copy<true>(pout + mfft / 2 + (3 * mfft / 4) * (k - 1), &inFreqTmp[0], (3 * mfft / 4));
				}
			}
			else // upper sideband
			{
				if (k == 0)
				{
					copy<false>(pout, &inFreqTmp[mfft / 4], mfft / 2);
				}
				else
				{
					copy<false>(pout + mfft / 2 + (3 * mfft / 4) * (k - 1), &inFreqTmp[0], (3 * mfft / 4));
				}
			}
			// result now in this->obuffers[]
		}

		if (decimate_count == 0)
		{
			outputbuffer->WriteDone();
			pout = nullptr;
		}
		else
		{
			pout += mfft / 2 + (3 * mfft / 4) * (fftPerBuf - 1);
		}
	} // while(run)
	  //    DbgPrintf((char *) "r2iqThreadf idx %d pthread_exit %u\n",(int)this->t, pthread_self());

	fftwf_free(inFreqTmp);
	fftwf_destroy_plan(plan_f2t_c2c);
	return 0;
}
