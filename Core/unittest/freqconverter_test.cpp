#include "dsp/freqConverter.h"
#include "dsp/ringbuffer.h"

#include "CppUnitTestFramework.hpp"

namespace {
    struct FreqConverterFixture {};
}

TEST_CASE(FreqConverterFixture, BasicTest)
{
    auto input = ringbuffer<float>(128);
    auto freqoutput = ringbuffer<fftwf_complex>(1024);
    auto timeoutput = ringbuffer<fftwf_complex>(1024);

    input.setBlockSize(transferSize / 2);
    FreqConverter r2c(&input, &freqoutput);
    auto c2c = FreqBackConverter(&freqoutput, &timeoutput);

    r2c.start();
    c2c.start();

    const int count = 1;
    for (int i = 0; i < count; i++) {
        auto *ptr = input.getWritePtr();
        memset(ptr, 0x5A, input.getBlockSize());
        input.WriteDone();
    }

    for (int j = 0; j < count; j++) {
        auto *ptr = timeoutput.getReadPtr();
        timeoutput.ReadDone();
    }

    c2c.stop();
    r2c.stop();

    printf("c2c Perf: %f\n", c2c.getProcessTime());
    printf("R2C Perf: %f\n", r2c.getProcessTime());
}

TEST_CASE(FreqConverterFixture, ThreadsTest)
{
    auto input = ringbuffer<float>(12);
    auto freqoutput = ringbuffer<fftwf_complex>(128);
    auto timeoutput = ringbuffer<fftwf_complex>(128);

    FreqConverter r2c(&input, &freqoutput);
    auto c2c = FreqBackConverter(&freqoutput, &timeoutput);

    input.setBlockSize(transferSize / 2);
    r2c.start();
    c2c.start();

    const int wcount = 2;
    const int rcount = 1 * (transferSize / 2 / FFTN_R_ADC / 4);

    auto thread1 = std::thread([&input, wcount] {
        for (int i = 0; i < wcount; i++) {
            auto *ptr = input.getWritePtr();
            memset(ptr, 0x5A, input.getBlockSize());
            input.WriteDone();
        }
    });

    auto thread2 = std::thread([&timeoutput, rcount, this] {
        for (int j = 0; j < rcount ; j++) {
            auto *ptr = timeoutput.getReadPtr();
            timeoutput.ReadDone();
        }
    });

    thread2.join();
    thread1.join();

    c2c.stop();
    r2c.stop();

    printf("c2c Perf: %f\n", c2c.getProcessTime());
    printf("R2C Perf: %f\n", r2c.getProcessTime());
}