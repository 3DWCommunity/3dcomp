#pragma once

#include <basis/seadTypes.h>
#include <math/seadVector.h>

namespace al {
    class RumbleCalculator {
    public:
        RumbleCalculator(f32, f32, f32, u32);

        virtual void calcValues(sead::Vector3f*, const sead::Vector3f&) = 0;

        void start(u32);
        void calc();
        void reset();

        u32 _8;
        u32 _C;
        f32 _10;
        f32 _14;
        f32 _18;
        f32 _1C;
        f32 _20;
        f32 _24;
    };
};  // namespace al