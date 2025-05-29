#pragma once

namespace al {
class LiveActor;

bool trySyncStageSwitchAppear(LiveActor*);
bool trySyncStageSwitchKill(LiveActor*);
bool trySyncStageSwitchAppearAndKill(LiveActor*);
bool tryListenStageSwitchAppear(LiveActor*);
bool tryListenStageSwitchKill(LiveActor*);
void syncSensorScaleY(LiveActor*);
void setMaterialCode(LiveActor*, const char*);

void initMapPartsActorNoPlacementInfo(LiveActor *, const ActorInitInfo &, const char *);
}  // namespace al
