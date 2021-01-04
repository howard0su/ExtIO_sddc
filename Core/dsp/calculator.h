#pragma once

#include "ringbuffer.h"
#include "signalparameters.h"
#include <chrono>
#include <thread>

using namespace std::chrono;

template<typename TINPUT, typename TOUTPUT> class calculator: public SignalParameters {
public:
    // start the thread
    void start() {
        run = true;
        timesum = 0s;
        count = 0;
        thread = std::thread(
            [this]()
            {
                while(run){
                    auto starttime = high_resolution_clock::now();
                    count++;
                    process();

                    timesum += high_resolution_clock::now() - starttime;
                }
            });
    }

    void stop() {
        run = false;
        input->Stop();
        thread.join();
    }

    float getProcessTime() const {
        return timesum.count() / count;
    }

protected:
    calculator(ringbuffer<TINPUT> *_input) :
        input(_input),
        output(nullptr)
    {
    }

    calculator(ringbuffer<TINPUT> *_input, ringbuffer<TOUTPUT> *_output) :
        input(_input),
        output(_output)
    {
    }

    virtual void process() = 0;

    ringbuffer<TINPUT> *input;
    ringbuffer<TOUTPUT> *output;
private:
    std::thread thread;
    duration<float> timesum;
    int count;
    bool run;
};