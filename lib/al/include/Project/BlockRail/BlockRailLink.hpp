#pragma once

#include "Library/Actor/ActorInitInfo.hpp"
#include "Library/Yaml/ByamlIter.hpp"
#include <math/seadQuat.h>
#include <basis/seadTypes.h>

namespace al {
    class BlockRailShape;

    class BlockRailLink {
    public:
        BlockRailLink(int);

        void init(const ActorInitInfo &, const ByamlIter &);
        void init(const sead::Quatf &, const sead::Vector3f &, const ByamlIter &);
        void calcOffset(const sead::Vector3f &);
        void updateLinkedTrans(const sead::Vector3f &);
        void setShape(BlockRailShape *);
        void addPrev(BlockRailLink *);
        void addNext(BlockRailLink *);
        bool isRide(f32 *, const sead::Vector3f &, const sead::Vector3f &) const;
        f32 getTotalLength() const;
        void calcPosAndDir(sead::Vector3f *, sead::Vector3f *, f32) const;
        void calcPos(sead::Vector3f *, f32) const;
        void calcDir(sead::Vector3f *, f32) const;
        void calcNearestParam(sead::Vector3f *, f32 *, const sead::Vector3f &) const;
        bool isTerminate() const;
        BlockRailLink* getPrevLink(int) const;
        BlockRailLink* getNextLink(int) const;
        bool isPrevLink(const BlockRailLink *) const;
        bool isNextLink(const BlockRailLink *) const;
        static void tryConnect(BlockRailLink *, BlockRailLink *, f32);

        BlockRailShape* mShape;             // 0x00
        BlockRailLink** mPrevLinks;         // 0x08
        BlockRailLink** mNextLinks;         // 0x10
        int mNumPrevLinks;                  // 0x18
        int mNumNextLinks;                  // 0x1C
        int _20;
        u8 _24;
    };
};