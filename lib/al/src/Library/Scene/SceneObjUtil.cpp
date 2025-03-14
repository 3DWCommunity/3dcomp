#include "Library/Scene/SceneObjUtil.hpp"

namespace al {
    ISceneObj* createSceneObj(const IUseSceneObjHolder *pHolder, int objID) {
        return pHolder->getSceneObjHolder()->create(objID);
    }

    void setSceneObj(const IUseSceneObjHolder *pHolder, ISceneObj *pObj, int objID) {
        pHolder->getSceneObjHolder()->setSceneObj(pObj, objID);
    }

    ISceneObj* getSceneObj(const IUseSceneObjHolder *pHolder, int objID) {
        return pHolder->getSceneObjHolder()->getObj(objID);
    }

    ISceneObj* tryGetSceneObj(const IUseSceneObjHolder *pHolder, int objID) {
        return pHolder->getSceneObjHolder()->tryGetObj(objID);
    }

    bool isExistSceneObj(const IUseSceneObjHolder *pHolder, int objID) {
        return pHolder->getSceneObjHolder()->isExist(objID);
    }
};