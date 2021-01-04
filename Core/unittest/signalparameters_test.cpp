#include "dsp/signalparameters.h"

#include "CppUnitTestFramework.hpp"

namespace {
    class SignalFixture : public SignalParameters {};
}

TEST_CASE(SignalFixture, BasicTest)
{
    auto *signal = new SignalParameters();
    delete signal;
}

TEST_CASE(SignalFixture, BasicTest2)
{
    this->setDecimate(1);

    CHECK_EQUAL(1, mdecimation);

    this->setDecimate(2);
    CHECK_EQUAL(2, mdecimation);
    CHECK_EQUAL(1024, mfft);
    CHECK_EQUAL(4, mradio);

    this->setFreqOffset(0.5);
    this->setDecimate(1);
    CHECK_EQUAL(2048, mtunebin);

}
