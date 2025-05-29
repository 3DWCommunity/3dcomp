#pragma once

#include <math/seadVector.h>
#include <basis/seadTypes.h>

namespace al {
    class BlockRailRouteSelecter;
    class BlockRailLink;

    class BlockRailRider {
    public:
        BlockRailRider();

        void move(f32, sead::Vector3f *, sead::Vector3f *);
        bool calcPosAndDir(sead::Vector3f *, sead::Vector3f *) const;
        BlockRailLink* trySelectPrevLink() const;
        BlockRailLink* trySelectNextLink() const;
        BlockRailLink* selectRoute(BlockRailLink *, BlockRailLink *) const;
        bool calcDir(sead::Vector3f *) const;
        void setRailPart(BlockRailLink *, f32);
        void setRouteSelecter(BlockRailRouteSelecter *);
        void reverse();
        bool isRide() const;
        
        BlockRailLink* mRailLink;               // 0x00
        BlockRailRouteSelecter* mSelecter;      // 0x08
        f32 _10;
        u8 _14;
        u8 _15;
        u8 _16;
    };
};