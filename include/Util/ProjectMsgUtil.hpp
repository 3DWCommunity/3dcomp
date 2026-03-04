#pragma once

#include <basis/seadTypes.h>

namespace al {
    class SensorMsg;
    class ComboCounter;
};  // namespace al

namespace rc {
    al::ComboCounter* tryGetMsgComboCount(const al::SensorMsg*);
};