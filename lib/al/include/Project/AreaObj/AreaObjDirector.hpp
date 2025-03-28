#pragma once

#include <basis/seadTypes.h>
#include <math/seadVector.h>

namespace al {
class AreaObj;

class AreaObjDirectorGrid {
public:
    AreaObjDirectorGrid(s32, s32);

    void expandGrid(AreaObj*);
    void endInit();

    s32 _0;
    s32 _4;
    sead::Vector3f _8;
    sead::Vector3f _14;
};
}  // namespace al
