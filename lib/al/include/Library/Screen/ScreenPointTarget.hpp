#pragma once

#include <math/seadVector.h>

namespace al {
    class ScreenPointTarget;
    class ScreenPointer;

    sead::Vector3f* getScreenPointTargetPos(const ScreenPointTarget*);
    sead::Vector3f* getHitScreenPointTargetPos(const ScreenPointer*);
};  // namespace al