#include "Library/StageSwitch/StageSwitchFunc.hpp"
#include "Library/StageSwitch/Core/IUseStageSwitch.hpp"
#include "Library/StageSwitch/StageSwitchAccesser.hpp"
#include "Library/StageSwitch/Core/StageSwitchKeeper.hpp"

namespace al {
    int findSwitchNo(const IUseStageSwitch *pStageSwitch, const char *pSwitchName) {
        auto keeper = pStageSwitch->getStageSwitchKeeper();
        if (keeper != nullptr) {
            auto accessor = keeper->tryGetStageSwitchAccesser(pSwitchName);
            if (accessor != nullptr) {
                accessor->isEnableRead();
                return accessor->mSwitchNo;
            }
        }

        return -1;
    }

    bool isUsingSwitchNo(const IUseStageSwitch *pSwitch, int switchNo) {
        return pSwitch->getStageSwitchKeeper()->isUsingSwitchNo(switchNo);
    }

    bool isValidSwitchAppear(const IUseStageSwitch *pSwitch) {
        auto keeper = pSwitch->getStageSwitchKeeper();
        if (keeper != nullptr) {
            auto accessor = keeper->tryGetStageSwitchAccesser("SwitchAppear");
            if (accessor != nullptr) {
                accessor->isEnableRead();
                return accessor->isValid();
            }
        }

        return false;
    }

    bool isOnSwitchAppear(const IUseStageSwitch *pSwitch) {
        auto keeper = pSwitch->getStageSwitchKeeper();
        if (keeper != nullptr) {
            auto accessor = keeper->tryGetStageSwitchAccesser("SwitchAppear");
            if (accessor != nullptr) {
                accessor->isEnableRead();
                return accessor->isOnSwitch();
            }
        }

        return false;
    }

    bool isValidSwitchKill(const IUseStageSwitch *pSwitch) {
        auto keeper = pSwitch->getStageSwitchKeeper();
        if (keeper != nullptr) {
            auto accessor = keeper->tryGetStageSwitchAccesser("SwitchKill");
            if (accessor != nullptr) {
                accessor->isEnableRead();
                return accessor->isValid();
            }
        }

        return false;
    }
    
    bool isValidSwitchDeadOn(const IUseStageSwitch *pSwitch) {
        auto keeper = pSwitch->getStageSwitchKeeper();
        if (keeper != nullptr) {
            auto accessor = keeper->tryGetStageSwitchAccesser("SwitchDeadOn");
            if (accessor != nullptr) {
                accessor->isEnableRead();
                return accessor->isValid();
            }
        }

        return false;
    }

    void onSwitchDeadOn(IUseStageSwitch *pSwitch) {
        auto keeper = pSwitch->getStageSwitchKeeper();
        if (keeper != nullptr) {
            auto accessor = keeper->tryGetStageSwitchAccesser("SwitchDeadOn");
            if (accessor != nullptr) {
                accessor->isEnableRead();
                accessor->onSwitch();
            }
        }
    }

    void offSwitchDeadOn(IUseStageSwitch *pSwitch) {
        auto keeper = pSwitch->getStageSwitchKeeper();
        if (keeper != nullptr) {
            auto accessor = keeper->tryGetStageSwitchAccesser("SwitchDeadOn");
            if (accessor != nullptr) {
                accessor->isEnableRead();
                accessor->offSwitch();
            }
        }
    }

    bool tryOnSwitchDeadOn(IUseStageSwitch *pSwitch) {
        auto keeper = pSwitch->getStageSwitchKeeper();
        if (keeper != nullptr) {
            auto accessor = keeper->tryGetStageSwitchAccesser("SwitchDeadOn");
            if (accessor != nullptr) {
                accessor->isEnableRead();
                if (accessor->isValid()) {
                    if (!accessor->isOnSwitch()) {
                        accessor->onSwitch();
                        return true;
                    }
                    else {
                        return false;
                    }
                }
                else {
                    return false;
                }
            }
        }

        return false;
    }

    bool tryOffSwitchDeadOn(IUseStageSwitch *pSwitch) {
        auto keeper = pSwitch->getStageSwitchKeeper();
        if (keeper != nullptr) {
            auto accessor = keeper->tryGetStageSwitchAccesser("SwitchDeadOn");
            if (accessor != nullptr) {
                accessor->isEnableRead();
                if (accessor->isValid()) {
                    if (accessor->isOnSwitch()) {
                        accessor->offSwitch();
                        return true;
                    }
                    else {
                        return false;
                    }
                }
                else {
                    return false;
                }
            }
        }

        return false;
    }
};