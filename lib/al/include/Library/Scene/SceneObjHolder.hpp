#pragma once

#include "Library/Scene/ISceneObj.hpp"
#include "Library/Scene/IUseSceneObjHolder.hpp"

typedef al::ISceneObj* (*CreateFunc)(int);

namespace al {
    class SceneObjHolder : public IUseSceneObjHolder {
    public:
        SceneObjHolder(CreateFunc, int);
        ISceneObj* create(int);
        ISceneObj* tryGetObj(int) const;
        ISceneObj* getObj(int) const;
        bool isExist(int) const;
        void setSceneObj(ISceneObj *, int);
        void initAfterPlacementSceneObj(const ActorInitInfo &);

        CreateFunc mFunc;           // 0x00
        ISceneObj** mObjs;          // 0x08
        int mNumObjs;               // 0x10
    };
};