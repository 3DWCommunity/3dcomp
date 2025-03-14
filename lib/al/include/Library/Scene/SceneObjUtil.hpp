#pragma once

#include "Library/Scene/SceneObjHolder.hpp"

namespace al {
    ISceneObj* createSceneObj(const IUseSceneObjHolder *, int);
    void setSceneObj(const IUseSceneObjHolder *, ISceneObj *, int);
    ISceneObj* getSceneObj(const IUseSceneObjHolder *, int);
    ISceneObj* tryGetSceneObj(const IUseSceneObjHolder *, int);
    bool isExistSceneObj(const IUseSceneObjHolder *, int);
};