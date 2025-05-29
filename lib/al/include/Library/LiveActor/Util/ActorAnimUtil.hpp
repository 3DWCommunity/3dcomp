#pragma once

#include <basis/seadTypes.h>

namespace al {
    class LiveActor;

    bool tryStartMclAnimIfExist(LiveActor *, const char *);
    void setMclAnimFrameAndStop(LiveActor *, f32);
};