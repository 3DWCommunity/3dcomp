#pragma once

#include "Library/Scene/ISceneObj.hpp"
#include "Library/Scene/IUseSceneObjHolder.hpp"

class GameDataHolderAccessor {
public:
    GameDataHolderAccessor(const al::IUseSceneObjHolder*);

    al::ISceneObj* mSceneObj;  // 0x00
};
