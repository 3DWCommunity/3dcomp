#pragma once

#include <basis/seadTypes.h>

namespace al {
    class ActorInitInfo;

    const u8* getMapPartsResourceYaml(const ActorInitInfo &, const char *);
};