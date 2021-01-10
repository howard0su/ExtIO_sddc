#pragma once

#include "r2iq.h"
#include "fftw3.h"

// use up to this many threads
#define N_MAX_R2IQ_THREADS 4

class fft_mt_r2iq : public r2iqControlClass
{
public:
    fft_mt_r2iq();
    virtual ~fft_mt_r2iq();

    float setFreqOffset(float offset);

    void Init(float gain, int16_t** buffers, float** obuffers);
    void TurnOn();
    void TurnOff(void);
    bool IsOn(void);
    void DataReady(void);

private:
    int16_t** buffers;    // pointer to input buffers
    float** obuffers;   // pointer to output buffers
    int bufIdx;         // index to next buffer to be processed
    volatile std::atomic<int> cntr;           // counter of input buffer to be processed
    r2iqThreadArg* lastThread;

    float GainScale;
    int mfftdim [NDECIDX]; // FFT N dimensions: mfftdim[k] = halfFft / 2^k
    int mtunebin;

    void *r2iqThreadf(r2iqThreadArg *th);   // thread function

    fftwf_complex **filterHw;       // Hw complex to each decimation ratio

    uint32_t processor_count;
    r2iqThreadArg* threadArgs[N_MAX_R2IQ_THREADS];
    std::condition_variable cvADCbufferAvailable;  // unlock when a sample buffer is ready
    std::mutex mutexR2iqControl;                   // r2iq control lock
    std::thread* r2iq_thread[N_MAX_R2IQ_THREADS]; // thread pointers
};
