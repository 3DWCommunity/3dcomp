#pragma once

#include <math/seadVector.h>

namespace al {
    class BezierCurve;
    class LinearCurve;

    class RailPart {
    public:
        RailPart();

        void init(const sead::Vector3f &, const sead::Vector3f &, const sead::Vector3f &, const sead::Vector3f &);
        void setUp(sead::Vector3f &, sead::Vector3f &);
        void setAccel(f32, f32);
        void getAccels(f32 *, f32 *);
        void setAngleS(f32);
        void setAngleE(f32);
        bool getAngleS(f32 *);
        bool getAngleE(f32 *);
        void calcPos(sead::Vector3f *, f32) const;
        void calcVelocity(sead::Vector3f *, f32) const;
        void calcUpDir(sead::Vector3f *, f32) const;
        f32 getPartLength() const;
        void calcDir(sead::Vector3f *, f32) const;
        void calcStartPos(sead::Vector3f *) const;
        void calcEndPos(sead::Vector3f *) const;
        f32 calcLength(f32, f32, int) const;
        f32 calcCurveParam(f32) const;
        f32 calcNearestParam(const sead::Vector3f &, f32) const;
        f32 calcNearestPos(sead::Vector3f *, const sead::Vector3f &, f32) const;
        void calcNearestLength(f32 *, const sead::Vector3f &, f32, f32) const;

        BezierCurve* mBezierCurve = nullptr;          // 0x00
        LinearCurve* mLinearCurve = nullptr;          // 0x08
        u32 _10 = 0;
        sead::Vector3f _14 = sead::Vector3f::ey;
        sead::Vector3f _20 = sead::Vector3f::ey;
        f32 _2C = 0.0f;
        f32 _30= 0.0f;
        f32 _34= 0.0f;
        f32 _38= 0.0f;
        u8 _3C = 0;
        u8 _3D = 0;
    };
};