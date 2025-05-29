#pragma once

#include <math/seadVector.h>
#include <basis/seadTypes.h>

namespace al {
    class BlockRailRouteSelecter;
    class BlockRailLink;

    class BlockRailRider {
    public:

        void setRailPart(BlockRailLink *, f32);
        
        BlockRailLink* mRailLink;               // 0x00
        BlockRailRouteSelecter* mSelecter;      // 0x08
        f32 _10;
        u8 _14;
        u8 _15;
        u8 _16;
    };
};