#pragma once

#include "Library/Nerve/NerveStateBase.hpp"
#include <basis/seadTypes.h>
#include <math/seadVector.h>

namespace al {
    class LiveActor;
    class ActorInitInfo;
};  // namespace al

class ActorStateDemoCameraParam {
public:
    ActorStateDemoCameraParam(int, int, int, const sead::Vector3f*, const sead::Vector3f*);

    int _0;
    int _4;
    int _8;
    const sead::Vector3f* _10;
    const sead::Vector3f* _18;
    u64 _20;
    u64 _28;
    u64 _30;
};

class ActorStateDemoCamera : public al::ActorStateBase {
public:
    ActorStateDemoCamera(al::LiveActor*, const al::ActorInitInfo&, const char*, const ActorStateDemoCameraParam*, bool);
};