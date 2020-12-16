#pragma once

#include <stdint.h>

#include "config.h"
#include "FX3Class.h"

class RadioHardware {
public:
    RadioHardware(fx3class* fx3) : Fx3(fx3), gpios(0) {}

    virtual ~RadioHardware();
    virtual const char* getName() = 0;
    virtual void getFrequencyRange(int64_t& low, int64_t& high) = 0;
    virtual float getGain() { return BBRF103_GAINFACTOR; }
    virtual void Initialize() = 0;
    virtual bool UpdatemodeRF(rf_mode mode) = 0;
    virtual bool UpdateattRF(int attIndex) = 0;
    virtual uint64_t TuneLo(uint64_t freq) = 0;

    virtual int getRFSteps(const float** steps ) { return 0; }
    virtual int getIFSteps(const float** steps ) { return 0; }
    virtual bool UpdateGainIF(int attIndex) { return false; }

    bool FX3producerOn() { return Fx3->Control(STARTFX3); }
    bool FX3producerOff() { return Fx3->Control(STOPFX3); }

    virtual uint32_t getSampleRate();

    bool FX3SetGPIO(uint32_t mask);
    bool FX3UnsetGPIO(uint32_t mask);

protected:
    fx3class* Fx3;
    uint32_t gpios;
};

class BBRF103Radio : public RadioHardware {
public:
    BBRF103Radio(fx3class* fx3);
    const char* getName() override { return "BBRF103"; }
    float getGain() override { return BBRF103_GAINFACTOR; }
    void getFrequencyRange(int64_t& low, int64_t& high) override;
    void Initialize() override;
    bool UpdatemodeRF(rf_mode mode) override;
    uint64_t TuneLo(uint64_t freq) override;
    bool UpdateattRF(int attIndex) override;
    bool UpdateGainIF(int attIndex) override;

    int getRFSteps(const float** steps ) override;
    int getIFSteps(const float** steps ) override;

private:
    static const int step_size = 29;
    static const float steps[step_size];
    static const float hfsteps[3];

    static const int if_step_size = 16;
    static const float if_steps[if_step_size];
};

class RX888Radio : public BBRF103Radio {
public:
    RX888Radio(fx3class* fx3) : BBRF103Radio(fx3) {}
    const char* getName() override { return "RX888"; }
    float getGain() override { return RX888_GAINFACTOR; }
};

class RX888R2Radio : public RadioHardware {
public:
    RX888R2Radio(fx3class* fx3);
    const char* getName() override { return "RX888 mkII"; }
    float getGain() override { return RX888_GAINFACTOR; }
    void getFrequencyRange(int64_t& low, int64_t& high) override;
    void Initialize() override;
    bool UpdatemodeRF(rf_mode mode) override;
    uint64_t TuneLo(uint64_t freq) override;
    bool UpdateattRF(int attIndex) override;
    bool UpdateGainIF(int attIndex) override;

    int getRFSteps(const float** steps ) override;
    int getIFSteps(const float** steps ) override;

private:
    static const int  hf_rf_step_size = 64;
    static const int  hf_if_step_size = 127;
    static const int vhf_if_step_size = 16;
    static const int vhf_rf_step_size = 29;

    float  hf_rf_steps[hf_rf_step_size];
    float  hf_if_steps[hf_if_step_size];
    static const float vhf_rf_steps[vhf_rf_step_size];
    static const float vhf_if_steps[vhf_if_step_size];
};

class RX999Radio : public RadioHardware {
public:
    RX999Radio(fx3class* fx3);
    const char* getName() override { return "RX999"; }
    float getGain() override { return RX888_GAINFACTOR; }

    void getFrequencyRange(int64_t& low, int64_t& high) override;
    void Initialize() override;
    bool UpdatemodeRF(rf_mode mode) override;
    uint64_t TuneLo(uint64_t freq) override;
    bool UpdateattRF(int attIndex) override;
    bool UpdateGainIF(int attIndex) override;

    int getRFSteps(const float** steps ) override;
    int getIFSteps(const float** steps ) override;

    uint32_t getSampleRate() override;

private:
    static const int if_step_size = 127;

    float  if_steps[if_step_size];
};

class HF103Radio : public RadioHardware {
public:
    HF103Radio(fx3class* fx3) : RadioHardware(fx3) {}
    const char* getName() override { return "HF103"; }
    float getGain() override { return HF103_GAINFACTOR; }

    void getFrequencyRange(int64_t& low, int64_t& high) override;

    void Initialize() override;

    bool UpdatemodeRF(rf_mode mode) override;

    uint64_t TuneLo(uint64_t freq) override { return 0; }
    
    bool UpdateattRF(int attIndex) override;

    int getRFSteps(const float** steps ) override;

private:
    static const int step_size = 64;
    float steps[step_size];
};

class DummyRadio : public RadioHardware {
public:
    DummyRadio() : RadioHardware(nullptr) {}
    const char* getName() override { return "HF103"; }

    void getFrequencyRange(int64_t& low, int64_t& high) override
    { low = 0; high = 6ll*1000*1000*1000;}
    void Initialize() override {}
    bool UpdatemodeRF(rf_mode mode) override { return true; }
    bool UpdateattRF(int attIndex) override { return true; }
    uint64_t TuneLo(uint64_t freq) override { return freq; }
};
