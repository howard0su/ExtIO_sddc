#include "RadioHardware.h"

void HF103Radio::Initialize()
{
    // initialize steps
    for (uint8_t i = 0 ; i < step_size; i++) {
        this->steps[step_size - i - 1] = -(
            ((i & 0x01) != 0) * 0.5f +
            ((i & 0x02) != 0) * 1.0f +
            ((i & 0x04) != 0) * 2.0f +
            ((i & 0x08) != 0) * 4.0f +
            ((i & 0x010) != 0) * 8.0f +
            ((i & 0x020) != 0) * 16.0f
        );
    }
}

static const int64_t low_limit[] = {0};
static const int64_t high_limit[] = {M(32)};

int HF103Radio::getFrequencyRanges(const int64_t** low, const int64_t** high)
{
    *low = low_limit;
    *high = high_limit;

    return 1;
}

bool HF103Radio::UpdateFrequencyRange(int index)
{
    if (index != 0)
        return false;

    return true;
}

bool HF103Radio::UpdateattRF(int att)
{
    if (att > step_size - 1) att = step_size - 1;
    if (att < 0) att = 0;
    uint8_t d = step_size - att - 1;

    DbgPrintf("UpdateattRF %f \n", this->steps[att]);

    return Fx3->SetArgument(DAT31_ATT, d);
}

int HF103Radio::getRFSteps(const float** steps )
{
    *steps = this->steps;

    return step_size;
}
