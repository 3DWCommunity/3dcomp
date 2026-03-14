#pragma once

#include <math/seadVector.h>

namespace al {
    struct PlacementInfo;
    class ActorInitInfo;
    class PlacementId;

    bool isValidInfo(const PlacementId&);
    bool isPlaced(const ActorInitInfo&);
    void getObjectName(const char**, const ActorInitInfo&);
    void getObjectName(const char**, const PlacementInfo&);
    bool tryGetObjectName(const char**, const PlacementInfo&);
    bool tryGetObjectName(const char**, const ActorInitInfo&);
    bool tryGetStringArg(const char**, const PlacementInfo&, const char*);
    bool isObjectName(const ActorInitInfo&, const char*);
    bool isObjectName(const PlacementInfo&, const char*);
    bool isObjectNameSubStr(const ActorInitInfo&, const char*);
    bool isObjectNameSubStr(const PlacementInfo&, const char*);

    bool tryGetStringArg(const char**, const ActorInitInfo&, const char*);

    bool tryGetClassName(const char**, const ActorInitInfo&);
    bool tryGetClassName(const char**, const PlacementInfo&);
    bool tryGetPlacementInfoByKey(PlacementInfo*, const PlacementInfo&, const char*);
    void getClassName(const char**, const ActorInitInfo&);
    void getClassName(const char**, const PlacementInfo&);
    bool isClassName(const ActorInitInfo&, const char*);
    bool isClassName(const PlacementInfo&, const char*);
    void getDisplayName(const char**, const ActorInitInfo&);
    bool tryGetDisplayName(const char**, const ActorInitInfo&);
    void getDisplayName(const char**, const PlacementInfo&);
    bool tryGetDisplayName(const char**, const PlacementInfo&);
    void getPlacementTargetFile(const char**, const PlacementInfo&);
    bool tryGetTrans(sead::Vector3f*, const ActorInitInfo&);
    bool tryGetTrans(sead::Vector3f*, const PlacementInfo&);
    void multZoneMtx(sead::Vector3f*, const PlacementInfo&);
    void getTrans(sead::Vector3f*, const PlacementInfo&);

    bool tryGetArg(int*, const ActorInitInfo&, const char*);
    bool tryGetArg(f32*, const ActorInitInfo&, const char*);
    bool tryGetArg(bool*, const ActorInitInfo&, const char*);

    bool getChildLinkTR(sead::Vector3f*, sead::Vector3f*, const ActorInitInfo&, const char*, int);

    void getRotate(sead::Vector3f*, const PlacementInfo&);
}  // namespace al
