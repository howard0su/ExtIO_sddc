#include "dsp/calculator.h"
#include "dsp/converter.h"

#include "config.h"

#include "CppUnitTestFramework.hpp"

namespace {
    struct ConverterFixture {};
}

TEST_CASE(ConverterFixture, SingleThreadTest)
{
    auto input = ringbuffer<int16_t>(128);
    auto output= ringbuffer<float>(16);

    converter conv(&input, &output);

    input.setBlockSize(transferSize / 2);
    conv.start();
    const int count = 128;
    for (int i = 0; i < count; i++) {
        auto *ptr = input.getWritePtr();
        memset(ptr, 0x5A, input.getBlockSize());
        input.WriteDone();
    }

    for (int j = 0; j < count; j++) {
        auto *ptr = output.getReadPtr();
        REQUIRE_EQUAL(*ptr, 23130.0f);
        output.ReadDone();
    }

    conv.stop();
    printf("Perf: %f\n", conv.getProcessTime());
}

TEST_CASE(ConverterFixture, TwoThreadsThreadTest)
{
    auto input = ringbuffer<int16_t>(128);
    auto output= ringbuffer<float>(16);

    auto conv = converter(&input, &output);

    input.setBlockSize(transferSize / 2);
    conv.start();
    const int count = 1280;

    auto thread1 = std::thread([&input, count] {
        for (int i = 0; i < count; i++) {
            auto *ptr = input.getWritePtr();
            memset(ptr, 0x5A, input.getBlockSize());
            input.WriteDone();
        }
    });

    auto thread2 = std::thread([&output, count, this] {
        for (int j = 0; j < count; j++) {
            auto *ptr = output.getReadPtr();
            REQUIRE_EQUAL(*ptr, 23130.0f);
            output.ReadDone();
        }
    });

    thread2.join();
    thread1.join();

    conv.stop();
    printf("Perf: %f\n", conv.getProcessTime());
}