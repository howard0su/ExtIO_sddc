#pragma once

#define NDECIDX 10
#include "config.h"

class SignalParameters {
public:
    SignalParameters()
    {
        mtunebin = halfFft / 4;
        mfftdim[0] = halfFft;
        for (int i = 1; i < NDECIDX; i++)
        {
            mfftdim[i] = mfftdim[i - 1] / 2;
        }

        mratiodim[0] = 1;
	    for (int i = 1; i < NDECIDX; i++)
	    {
		    mratiodim[i] = mratiodim[i - 1] * 2;
	    }

        setDecimate(1);
    }

    virtual void setFreqOffset(float offset)
    {
        // align to 1/4 of halfft
        this->mtunebin = int(offset * halfFft / 4) * 4; // mtunebin step 4 bin  ?
        float delta = ((float)this->mtunebin / halfFft) - offset;
        float ret = delta * mradio; // ret increases with higher decimation
        DbgPrintf("offset %f mtunebin %d delta %f (%f)\n", offset, this->mtunebin, delta, ret);
    }

    virtual void setDecimate(int val)
    {
        mdecimation = val;
        mfft = mfftdim[mdecimation];
        mradio = mratiodim[mdecimation];
    }

    int getDecimate() { return mdecimation; }

protected:
    int mfft;
    int mradio;
    int mdecimation;
    int mtunebin;

    const int halfFft = FFTN_R_ADC / 2;    // half the size of the first fft at ADC 64Msps real rate (2048)
    const int fftPerBuf = transferSize / sizeof(short) / (3 * halfFft / 2) + 1; // number of ffts per buffer with 256|768 overlap

private:

    int mratiodim[NDECIDX];  // ratio
    int mfftdim[NDECIDX];

    // TODO
    float fc;
};
