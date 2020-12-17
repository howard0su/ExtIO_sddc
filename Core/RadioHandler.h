#ifndef RADIOHANDLER_H
#define RADIOHANDLER_H

#include "license.txt" 

#include "config.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdint.h>
#include "FX3Class.h"

class RadioHardware;
class r2iqControlClass;

struct shift_limited_unroll_C_sse_data_s;
typedef struct shift_limited_unroll_C_sse_data_s shift_limited_unroll_C_sse_data_t;

class RadioHandlerClass {
public:
    RadioHandlerClass();
    virtual ~RadioHandlerClass();
    bool Init(fx3class* Fx3, void (*callback)(float*, uint32_t), r2iqControlClass *r2iqCntrl = nullptr);
    bool Start(int srate_idx);
    bool Stop();
    bool Close();
    bool IsReady(){return true;}

    int GetRFAttSteps(const float **steps);
    int UpdateattRF(int attIdx);

    int GetIFGainSteps(const float **steps);
    int UpdateIFGain(int attIdx);

    bool UptDither (bool b);
    bool GetDither () {return dither;}
    bool UptRand (bool b);
    bool GetRand () {return randout;}
    bool UptsamplesADC(bool flag) { samplesADCflag = flag; return  samplesADCflag; }
    bool GetADCsamples() { return  samplesADCflag; }
    uint16_t GetFirmware() { return firmware; }

    int getRanges(const int64_t** low, const int64_t **high);
    bool SetRangeIndex(int index);
    int GetRangeIndex() const { return rangeIndex; }

    uint32_t getSampleRate();

    float getBps() const { return mBps; }
    float getSpsIF() const {return mSpsIF; }

    const char* getName();
    RadioModel getModel() { return radio; }

    bool GetBiasT_HF() { return biasT_HF; }
    void UpdBiasT_HF(bool flag);
    bool GetBiasT_VHF() { return biasT_VHF; }
    void UpdBiasT_VHF(bool flag);

    uint64_t TuneLO(uint64_t lo);

    void uptLed(int led, bool on);

#ifdef TRACE
    bool UptTrace( bool trace){ traceflag = trace; return traceflag; }
    bool GetTrace( ){return traceflag; }
#endif

private:
    void AdcSamplesProcess();
    void AbortXferLoop(int qidx);
    void CaculateStats();
    void OnDataPacket(int idx);
    r2iqControlClass* r2iqCntrl;

    void (*Callback)(float *data, uint32_t length);

    bool run;
    unsigned long count;    // absolute index

    bool dither;
    bool randout;
    bool biasT_HF;
    bool biasT_VHF;
    bool traceflag;
    bool samplesADCflag;
    uint16_t firmware;
    int rangeIndex;
    RadioModel radio;

    // transfer variables
    int16_t* buffers[QUEUE_SIZE];
    float* obuffers[QUEUE_SIZE];

    // threads
    std::thread adc_samples_thread;
    std::thread show_stats_thread;

    // stats
    unsigned long BytesXferred;
    unsigned long SamplesXIF;
    float	mBps;
    float	mSpsIF;

    fx3class *fx3;
    RadioHardware* hardware;

    std::mutex fc_mutex;
    std::mutex stop_mutex;
    float fc;
    shift_limited_unroll_C_sse_data_t* stateFineTune;
};

extern unsigned long Failures;

#endif
