#pragma once

#include <basis/seadTypes.h>

namespace al {
    class HitSensor;
    class SensorMsg;
    class ComboCounter;
};  // namespace al

namespace rc {
    al::ComboCounter* tryGetMsgComboCount(const al::SensorMsg*);

    bool isMsgAskControlUserId(const al::SensorMsg*, int);

    bool trySendMsgBlockToUpperObj(al::HitSensor*, al::HitSensor*, int, al::ComboCounter*);
    bool trySendMsgBlockToLowerObj(al::HitSensor*, al::HitSensor*, al::ComboCounter*);
};  // namespace rc