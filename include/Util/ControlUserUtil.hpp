#pragma once

#include <basis/seadTypes.h>

namespace al {
    class HitSensor;
    class LiveActor;
    class ScreenPointer;
};

namespace rc {
    s32 tryFindRelativeControlUserId(const al::LiveActor *, al::ScreenPointer *);
};