#pragma once

#include "Library/Factory/Factory.hpp"

namespace al {
    class BlockRailShape;

    template<typename T>
    BlockRailShape* createBlockRailShapeFunction(const char *pName) {
        return new T(pName);
    }

    class BlockRailShapeFactory : public Factory<BlockRailShapeFactory*> {
    public:
        BlockRailShapeFactory();
    };
};