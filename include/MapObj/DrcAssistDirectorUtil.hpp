#pragma once

#include <math/seadVector.h>

namespace al {
    class LiveActor;
};

namespace rc {
    bool tryCalcTouchPointerSlideDirOnWorldByPointer(sead::Vector3f*, const al::LiveActor*);
};