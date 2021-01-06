#include "dsp/ringbuffer.h"
#include "dsp/freqShifter.h"
#include "dsp/converter.h"
#include "dsp/freqConverter.h"

#include "CppUnitTestFramework.hpp"

namespace {
    struct FreqShifterFixture {};
}

TEST_CASE(FreqShifterFixture, BasicTest)
{
    auto input = ringbuffer<fftwf_complex>(128);
    auto output = ringbuffer<fftwf_complex>(128);

    FreqShifter shifter(&input, &output);
    input.setBlockSize(FFTN_R_ADC);

    shifter.start();

    shifter.stop();
}


TEST_CASE(FreqShifterFixture, End2EndTest)
{
    auto input = ringbuffer<int16_t>(8);
    auto floatoutput = ringbuffer<float>(16);
    auto freqoutput = ringbuffer<fftwf_complex>(16);
    auto shiftoutput = ringbuffer<fftwf_complex>(16);
    auto timeoutput = ringbuffer<fftwf_complex>(16);

    converter conv(&input, &floatoutput);
    FreqConverter r2c(&floatoutput, &freqoutput);
    FreqShifter shifter(&freqoutput, &shiftoutput);
    FreqBackConverter c2c(&shiftoutput, &timeoutput);
    input.setBlockSize(transferSize / sizeof(int16_t));

    conv.start();
    r2c.start();
    shifter.start();
    c2c.start();

    int count = 40;
    auto thread1 = std::thread([&input, count] {
        for (int i = 0; i < count; i++) {
            auto *ptr = input.getWritePtr();
            ptr[0] = 0x55;
            input.WriteDone();
        }
    });

    auto thread2 = std::thread([&timeoutput, count, this] {
        for (int j = 0; j < count * 8; j++) {
            auto *ptr = timeoutput.getReadPtr();
            timeoutput.ReadDone();
        }
    });

    thread1.join();
    thread2.join();

    c2c.stop();
    shifter.stop();
    r2c.stop();
    conv.stop();

    printf("buffer0 write:%d full:%d empty:%d\n", input.getWriteCount(), input.getFullCount(), input.getEmptyCount());
    printf("buffer1 write:%d full:%d empty:%d\n", floatoutput.getWriteCount(), floatoutput.getFullCount(), floatoutput.getEmptyCount());
    printf("buffer2 write:%d full:%d empty:%d\n", freqoutput.getWriteCount(), freqoutput.getFullCount(), freqoutput.getEmptyCount());
    printf("buffer3 write:%d full:%d empty:%d\n", shiftoutput.getWriteCount(), shiftoutput.getFullCount(), shiftoutput.getEmptyCount());
    printf("buffer4 write:%d full:%d empty:%d\n", timeoutput.getWriteCount(), timeoutput.getFullCount(), timeoutput.getEmptyCount());
}
