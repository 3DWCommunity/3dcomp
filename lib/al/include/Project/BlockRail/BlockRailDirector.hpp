#pragma once

#include "Library/Scene/ISceneObj.hpp"
#include <math/seadVector.h>
#include <basis/seadTypes.h>

namespace al {
    class BlockRail;
    class BlockRailRider;

    class BlockRailDirector : public ISceneObj {
    public:
        BlockRailDirector();

        virtual void initAfterPlacementSceneObj(const ActorInitInfo &);

        void registerBlockRail(BlockRail *);
        bool tryRideBlockRail(BlockRailRider *, const sead::Vector3f &, const sead::Vector3f &);

        BlockRail** mRails = nullptr;               // 0x08
        int mNumRails = 0;                          // 0x10
        int mMaxRails = 0x100;                      // 0x14
    };
};