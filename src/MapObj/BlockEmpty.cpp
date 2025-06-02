#include "MapObj/BlockEmpty.hpp"
#include "Util/ItemUtil.hpp"
#include "Library/Play/Placement/PlacementFunction.hpp"

BlockEmpty::BlockEmpty(const char *pName, const char *a2) : al::LiveActor(pName) {
    _158 = a2;
}
