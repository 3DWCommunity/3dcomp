#include "Library/Scene/SceneObjHolder.hpp"
#include "Library/Scene/ISceneObj.hpp"

namespace al {
    SceneObjHolder::SceneObjHolder(CreateFunc func, int numObjs) {
        mFunc = func;
        mNumObjs = numObjs;
        mObjs = new ISceneObj*[numObjs];

        for (int i = 0; i < mNumObjs; i++) {
            mObjs[i] = nullptr;
        }
    }

    ISceneObj* SceneObjHolder::create(int objID) {
        if (mObjs[objID] == nullptr) {
            mObjs[objID] = mFunc(objID);
            mObjs[objID]->initSceneObj();
            return mObjs[objID];
        }

        return mObjs[objID];
    }

    ISceneObj* SceneObjHolder::tryGetObj(int objID) const {
        return mObjs[objID];
    }

    ISceneObj* SceneObjHolder::getObj(int objID) const {
        return mObjs[objID];
    }

    bool SceneObjHolder::isExist(int objID) const {
        return mObjs[objID] != nullptr;
    }

    void SceneObjHolder::setSceneObj(ISceneObj *pObj, int objID) {
        mObjs[objID] = pObj;
    }

    void SceneObjHolder::initAfterPlacementSceneObj(const ActorInitInfo &rInfo) {
        for (int i = 0; i < mNumObjs; i++) {
            auto obj = mObjs[i];
            if (obj != nullptr) {
                obj->initAfterPlacementSceneObj(rInfo);
            }
        }
    }
};