#pragma once

#include <basis/seadTypes.h>

namespace al {
    class LiveActor;
    class ScreenPointer;
};

namespace rc {
    void addScoreByFactor(const al::LiveActor *, al::ScreenPointer *, const char *, f32, int);
};