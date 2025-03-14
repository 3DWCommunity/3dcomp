#pragma once

#include <math/seadVector.h>

namespace al {
    class BezierCurve {
    public:
        BezierCurve();

        f32 calcLength(f32, f32, int) const;
        void calcPos(sead::Vector3f *, f32) const;
        void calcVelocity(sead::Vector3f *, f32) const;
        f32 calcDeltaLength(f32) const;
        f32 calcCurveParam(f32) const;
        f32 calcNearestParam(const sead::Vector3f &, f32) const;
        f32 calcNearestLength(f32 *, const sead::Vector3f *, f32, f32) const;
        void calcNearestPos(sead::Vector3f *, const sead::Vector3f &, f32) const;

        sead::Vector3f _0 = sead::Vector3f::zero;
        sead::Vector3f _C = sead::Vector3f::zero;
        sead::Vector3f _18 = sead::Vector3f::zero;
    };
};