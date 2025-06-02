#pragma once

namespace al {
    class LiveActor;
    class ActorInitInfo;

};

namespace rc {
    const char* getBlockSuffixName(const al::ActorInitInfo &, bool);
};