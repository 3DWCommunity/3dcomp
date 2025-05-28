#pragma once

#include "Library/Yaml/ByamlIter.hpp"
#include <basis/seadTypes.h>
#include <math/seadQuat.h>

namespace al {
    class BlockRailShape {
    public:
        BlockRailShape(const char *);
        
        virtual void init(const sead::Quatf &, const sead::Vector3f &, const ByamlIter &);
        virtual bool isRide(f32 *, const sead::Vector3f &, const sead::Vector3f &) const;
        virtual f32 getTotalLength() const;
        virtual void calcPos(sead::Vector3f *, f32) const;
        virtual void calcDir(sead::Vector3f *, f32) const;
        virtual void calcNearestParam(sead::Vector3f *, f32 *, const sead::Vector3f &) const;
        virtual bool isTerminate() const;
        virtual void calcOffset(const sead::Vector3f &);
        virtual void updateLinkedTrans(const sead::Vector3f &);

        const char* mShape;         // 0x08
    };
};