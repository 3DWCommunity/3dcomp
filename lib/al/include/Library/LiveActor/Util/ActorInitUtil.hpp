#pragma once

#include "Library/Nerve/NerveAction.hpp"
#include <prim/seadSafeString.h>

namespace al {
    class LiveActor;
    class ActorInitInfo;
    class Nerve;
    struct PlacementInfo;

    void initActorChangeModelSuffix(LiveActor*, const ActorInitInfo&, const char*);
    void initActorWithArchiveName(LiveActor*, const ActorInitInfo&, const sead::SafeString&, const char*);
    void initActorWithArchiveCategoryName(LiveActor*, const ActorInitInfo&, const sead::SafeString&, const sead::SafeString&, const char*);
    void initActorWithArchiveNameWithPlacementInfo(LiveActor*, const ActorInitInfo&, const sead::SafeString&, const char*);
    void initActorWithArchiveNameNoPlacementInfo(LiveActor*, const ActorInitInfo&, const sead::SafeString&, const char*);

    void initNerve(LiveActor*, const Nerve*, s32);
    void initNerveAction(LiveActor*, const char*, alNerveFunction::NerveActionCollector*, s32);

    void initLinksActor(LiveActor*, const ActorInitInfo&, const char*, s32);

    void initActorPoseTRSV(LiveActor*);
    void initActorPoseTRMSV(LiveActor*);
    void initActorPoseTFSV(LiveActor*);
    void initActorPoseTFGSV(LiveActor*);
    void initActorPoseTQSV(LiveActor*);
    void initActorSRT(LiveActor*, const ActorInitInfo&);
    void initActorSRT_ParentY(LiveActor*, const ActorInitInfo&);

    void initMapPartsActor(LiveActor*, const ActorInitInfo&, const char*, int);

    void initActorSuffix(LiveActor*, const ActorInitInfo&, const char*);

    void initCreateActorWithPlacementInfo(LiveActor*, const ActorInitInfo&);

    void initCreateActorNoPlacementInfo(LiveActor*, const ActorInitInfo&);

    void initSubActorKeeperNoFile(LiveActor*, const ActorInitInfo&, int);

    void registerSubActorSyncClipping(LiveActor*, LiveActor*, bool);

    void initActor(LiveActor*, const ActorInitInfo&);

    void initExecutorWatchObj(LiveActor*, const ActorInitInfo&);

    void initActorAudioKeeperWithout3D(LiveActor*, const ActorInitInfo&, const char*, const char*);

    void initActorSceneInfo(LiveActor*, const ActorInitInfo&);

}  // namespace al
