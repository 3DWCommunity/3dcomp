#pragma once

#include <math/seadVector.h>

namespace al {
    class LiveActor;

    void setVelocityZero(LiveActor*);

    void resetPosition(LiveActor*, bool);

    void resetPosition(LiveActor*, const sead::Vector3f&, const sead::Vector3f&);

    void rotateQuatYDirDegree(LiveActor*, f32);

    void addVelocityToDirection(LiveActor*, const sead::Vector3f&, f32);

    void scaleVelocity(LiveActor*, f32);
};  // namespace al
