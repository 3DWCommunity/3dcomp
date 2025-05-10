#include "Library/StageSwitch/StageSwitchFunc.hpp"
#include "Library/StageSwitch/Core/IUseStageSwitch.hpp"
#include "Library/StageSwitch/StageSwitchAccesser.hpp"
#include "Library/StageSwitch/Core/StageSwitchKeeper.hpp"
#include "Library/Play/Placement/PlacementFunction.hpp"

namespace al {
    /*
    bool tryInitStageSwitch(IUseStageSwitch *pSwitch, StageSwitchDirector *pDirector, const PlacementInfo &rInfo) {
        s32 linkNum = al::calcLinkCountClassName(rInfo, "StageSwitch");
        if (linkNum != 0) {
            if (pSwitch->getStageSwitchKeeper() == nullptr) {
                pSwitch->initStageSwitchKeeper();

                if (al::calcLinkCountClassName(rInfo, "StageSwitch")) {
                    auto keeper = pSwitch->getStageSwitchKeeper();
                    keeper->_10 = pSwitch->getName();
                    keeper->init(pDirector, rInfo);
                }
            }

            return true;
        }

        return false;
    }
    */

    bool isValidStageSwitch(const IUseStageSwitch *pSwitch, const char *pSwitchName) {
        auto keeper = pSwitch->getStageSwitchKeeper();
        if (keeper != nullptr) {
            auto accessor = keeper->tryGetStageSwitchAccesser(pSwitchName);
            if (accessor != nullptr) {
                accessor->isEnableRead();
                return accessor->isValid();
            }
        }

        return false;
    }

    bool isOnStageSwitch(const IUseStageSwitch *pSwitch, const char *pSwitchName) {
        auto keeper = pSwitch->getStageSwitchKeeper();
        if (keeper != nullptr) {
            auto accessor = keeper->tryGetStageSwitchAccesser(pSwitchName);
            if (accessor != nullptr) {
                accessor->isEnableRead();
                return accessor->isOnSwitch();
            }
        }

        return false;
    }

    void onStageSwitch(IUseStageSwitch *pSwitch, const char *pSwitchName) {
        auto keeper = pSwitch->getStageSwitchKeeper();
        if (keeper != nullptr) {
            auto accessor = keeper->tryGetStageSwitchAccesser(pSwitchName);
            if (accessor != nullptr) {
                accessor->isEnableRead();
                accessor->onSwitch();
            }
        }
    }

    void offStageSwitch(IUseStageSwitch *pSwitch, const char *pSwitchName) {
        auto keeper = pSwitch->getStageSwitchKeeper();
        if (keeper != nullptr) {
            auto accessor = keeper->tryGetStageSwitchAccesser(pSwitchName);
            if (accessor != nullptr) {
                accessor->isEnableRead();
                accessor->offSwitch();
            }
        }
    }

    bool tryOnStageSwitch(IUseStageSwitch *pSwitch, const char *pSwitchName) {
        auto keeper = pSwitch->getStageSwitchKeeper();
        if (keeper != nullptr) {
            auto accessor = keeper->tryGetStageSwitchAccesser(pSwitchName);
            if (accessor != nullptr) {
                accessor->isEnableRead();
                if (accessor->isValid()) {
                    if (!accessor->isOnSwitch()) {
                        accessor->onSwitch();
                        return true;
                    }
                }
                else {
                    return false;
                }
            }
        }

        return false;
    }

    bool tryOffStageSwitch(IUseStageSwitch *pSwitch, const char *pSwitchName) {
        auto keeper = pSwitch->getStageSwitchKeeper();
        if (keeper != nullptr) {
            auto accessor = keeper->tryGetStageSwitchAccesser(pSwitchName);
            if (accessor != nullptr) {
                accessor->isEnableRead();
                if (accessor->isValid()) {
                    if (accessor->isOnSwitch()) {
                        accessor->offSwitch();
                        return true;
                    }
                }
                else {
                    return false;
                }
            }
        }

        return false;
    }

    bool isSameStageSwitch(const IUseStageSwitch *lhs, const IUseStageSwitch *rhs, const char *pSwitchName) {
        auto lhs_keeper = lhs->getStageSwitchKeeper();
        if (lhs_keeper == nullptr) {
            return false;
        }

        auto lhs_accessor = lhs_keeper->tryGetStageSwitchAccesser(pSwitchName);

        if (lhs_accessor == nullptr) {
            return false;
        }

        lhs_accessor->isEnableRead();

        auto rhs_keeper = rhs->getStageSwitchKeeper();
        if (rhs_keeper == nullptr) {
            return false;
        }

        auto rhs_accessor = rhs_keeper->tryGetStageSwitchAccesser(pSwitchName);

        if (rhs_accessor == nullptr) {
            return false;
        }

        rhs_accessor->isEnableRead();
        return lhs_accessor->isEqualSwitch(rhs_accessor);
    }

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