#pragma once

#include "Library/LiveActor/LiveActor.hpp"
#include <basis/seadTypes.h>

namespace al {
    class BlockRailParts;

    class BlockRailPartsGroup {
    public:
        BlockRailPartsGroup();

        void init(const ActorInitInfo &);
        void calcOffset(const sead::Vector3f &);
        void updateLinkedTrans(const sead::Vector3f &);
        void active();
        void specialActive(u32);
        void deactive();
        BlockRailParts* getParts(int) const;
        int calcEmptyLinkCount() const;

        BlockRailParts** mRailParts = nullptr;              // 0x00
        int mNumRailParts = 0;                              // 0x08
    };
};