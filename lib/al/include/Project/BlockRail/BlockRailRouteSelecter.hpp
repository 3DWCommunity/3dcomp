#pragma once

namespace al {
    class BlockRailRider;
    class BlockRailLink;

    class BlockRailRouteSelecter {
    public:
        virtual bool compareBlockRailRoute(const BlockRailRider *, const BlockRailLink *, const BlockRailLink*) const;
    };
};