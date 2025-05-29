#pragma once

#include <prim/seadSafeString.h>
#include "Library/Nerve/NerveAction.hpp"

namespace al {
    class LiveActor;
    class ActorInitInfo;
    class Nerve;
    struct PlacementInfo;

    void initActorChangeModelSuffix(LiveActor*, const ActorInitInfo&, const char*);
    void initActorWithArchiveName(LiveActor*, const ActorInitInfo&, const sead::SafeString&,
                                const char*);
    void initActorWithArchiveCategoryName(LiveActor*, const ActorInitInfo&, const sead::SafeString&,
                                        const sead::SafeString&, const char*);
    void initActorWithArchiveNameWithPlacementInfo(LiveActor*, const ActorInitInfo&,
                                                const sead::SafeString&, const char*);
    void initActorWithArchiveNameNoPlacementInfo(LiveActor*, const ActorInitInfo&,
                                                const sead::SafeString&, const char*);

    void initNerve(LiveActor*, const Nerve*, s32);
    void initNerveAction(LiveActor*, const char*, alNerveFunction::NerveActionCollector*, s32);

    void initLinksActor(LiveActor*, const ActorInitInfo&, const char*, s32);

    void initActorPoseTQSV(LiveActor*);

    void initMapPartsActor(LiveActor *, const ActorInitInfo &, const char *, int);
}  // namespace al
