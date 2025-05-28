#pragma once

#include <basis/seadTypes.h>
#include <math/seadMatrix.h>
#include <math/seadVector.h>

namespace al {
class ActorInitInfo;
struct PlacementInfo;
class PlacementId;
class LiveActor;

bool tryGetZoneMatrixTR(sead::Matrix34f*, const ActorInitInfo&);
bool tryGetZoneID(s32*, const PlacementInfo&);
bool tryGetDisplayOffset(sead::Vector3f*, const ActorInitInfo&);
bool tryGetDisplayScale(sead::Vector3f*, const ActorInitInfo&);

bool tryGetArg(s32*, const ActorInitInfo&, const char*);
bool tryGetArg(s32*, const PlacementInfo&, const char*);
bool tryGetArg(f32*, const ActorInitInfo&, const char*);
bool tryGetArg(f32*, const PlacementInfo&, const char*);

bool tryGetArg(bool*, const PlacementInfo&, const char*);

bool tryGetArg(bool*, const ActorInitInfo&, const char*);

bool tryGetScale(sead::Vector3f*, const PlacementInfo&);

bool tryGetMatrixTR(sead::Matrix34f*, const PlacementInfo&);

s32 calcLinkChildNum(const ActorInitInfo&, const char*);

s32 calcLinkChildNum(const PlacementInfo&, const char*);

s32 calcLinkCountClassName(const PlacementInfo&, const char*);

void getLinksInfo(PlacementInfo*, const PlacementInfo&, const char*);

void getLinksInfoByIndex(PlacementInfo*, const ActorInitInfo&, const char*, s32);

bool tryGetLinksInfo(PlacementInfo*, const PlacementInfo&, const char*);

bool tryGetPlacementInfoByKey(PlacementInfo*, const PlacementInfo&, const char*);

bool isEqualPlacementID(const PlacementInfo&, const PlacementInfo&);

bool isSingleMode(const ActorInitInfo&);

s32 getCountPlacementInfo(const PlacementInfo&);

bool tryGetPlacementID(PlacementId*, const PlacementInfo&);

bool tryGetPlacementInfoAndKeyNameByIndex(PlacementInfo*, const char**, const PlacementInfo&, s32);

bool tryGetPlacementInfoByIndex(PlacementInfo*, const PlacementInfo&, s32);

s32 calcLinkChildNum(const ActorInitInfo&, const char*);

const char* getLinksActorDisplayName(const ActorInitInfo &, const char *, int);

void initLinksActor(LiveActor *, const ActorInitInfo &, const char *, int);

}  // namespace al

namespace alPlacementFunction {
s32 getCameraId(const al::ActorInitInfo&);
s32 getLinkGroupId(al::PlacementId*, const al::ActorInitInfo&, const char*);
bool isEnableLinkGroupId(const al::ActorInitInfo&, const char*);
bool isEnableGroupClipping(const al::ActorInitInfo&);
bool getClippingGroupId(al::PlacementId*, const al::ActorInitInfo&);
bool getClippingViewId(al::PlacementId*, const al::PlacementInfo&);
bool getClippingViewId(al::PlacementId*, const al::ActorInitInfo&);
void getModelName(const char**, const al::PlacementInfo&);
bool tryGetModelName(const char**, const al::PlacementInfo&);
}  // namespace alPlacementFunction
