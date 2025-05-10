#pragma once

#include "Library/StageSwitch/Core/IUseStageSwitch.hpp"
#include <basis/seadTypes.h>

namespace al {
class StageSwitchAccesser;
class StageSwitchDirector;
struct PlacementInfo;

class StageSwitchKeeper {
public:
    StageSwitchKeeper();

    void init(StageSwitchDirector*, const PlacementInfo&);
    StageSwitchAccesser* tryGetStageSwitchAccesser(const char*) const;
    bool isUsingSwitchNo(s32);

    inline void setName(IUseStageSwitch *pSwitch) {
        _10 = pSwitch->getName();
    }

    StageSwitchAccesser* mAccessors = nullptr;
    s32 mLinkCount = 0;
    u32 _C;
    const char* _10 = nullptr;
};
}  // namespace al
