#pragma once

class SnowCover;

namespace al {
    class LiveActor;
    class ActorInitInfo;
};  // namespace al

namespace SnowCoverFunction {
    SnowCover* tryCreateSnowCover(al::LiveActor*, const al::ActorInitInfo&, const char*, bool, const char*);
};  // namespace SnowCoverFunction