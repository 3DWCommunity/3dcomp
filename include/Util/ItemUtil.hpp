#pragma once

namespace al {
    class LiveActor;
    class ActorInitInfo;
    class SensorMsg;
};  // namespace al

namespace rc {
    const char* getBlockSuffixName(const al::ActorInitInfo&, bool);

    bool isMsgForBlockAll(const al::SensorMsg*, const al::HitSensor*, const al::HitSensor*, f32);

    bool getMsgReturnValueForBlock(const al::SensorMsg*);
};  // namespace rc