#pragma once

#include <basis/seadTypes.h>

namespace al {
    class LiveActor;
    class ActorInitInfo;
    class SensorMsg;
    class HitSensor;
};  // namespace al

namespace rc {
    const char* getBlockSuffixName(const al::ActorInitInfo&, bool);

    int getItemType(const al::ActorInitInfo&);
    int getItemTypeByName(const char*);
    bool tryAppearItemPressDown(const al::LiveActor*, const char*);
    int getStepAppearItemPressDown();

    void addItemByHostInfo(al::LiveActor*, const al::ActorInitInfo&, const char*, const char*);

    bool isMsgForBlockAll(const al::SensorMsg*, const al::HitSensor*, const al::HitSensor*, f32);

    bool getMsgReturnValueForBlock(const al::SensorMsg*);
};  // namespace rc