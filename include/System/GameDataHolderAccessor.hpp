#pragma once

#include "Library/Scene/IUseSceneObjHolder.hpp"
#include "Library/Scene/ISceneObj.hpp"

class GameDataHolderAccessor {
public:
    GameDataHolderAccessor(const al::IUseSceneObjHolder*);

    al::ISceneObj* mSceneObj;       // 0x00
};
