#pragma once

#include "calculator.h"

class converter : public calculator<int16_t, float>
{
public:
    converter(ringbuffer<int16_t> *adc, ringbuffer<float> *output) : calculator(adc, output)
    {
    }

protected:
    void process() override
    {
        auto *src = input->getReadPtr();
        auto *dest = output->getWritePtr();

        // TODO: assume read/write has same block size
        for (int i = 0; i < getInputBlockSize(); ++i)
            dest[i] = float(src[i]);

        output->WriteDone();
        input->ReadDone();
    }
};
