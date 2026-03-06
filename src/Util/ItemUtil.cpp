#include "Util/ItemUtil.hpp"
#include "Library/ActorUtil.hpp"
#include "Library/Item/AcquireItemFunc.hpp"
#include "Library/LiveActor/LiveActor.hpp"
#include "Library/Play/Placement/PlacementUtil.hpp"
#include "Project/Base/StringUtil.hpp"

namespace rc {
    int tryInitItemByHostInfo(al::LiveActor* pActor, const al::ActorInitInfo& rInfo, int a3) {
        const char* type = "None";
        al::tryGetStringArg(&type, rInfo, "ItemType");
        if (al::isEqualString(type, "None")) {
            return -1;
        }

        pActor->initItemKeeper(a3);
        rc::addItemByHostInfo(pActor, rInfo, nullptr, nullptr);
        return rc::getItemType(rInfo);
    }

    int getItemType(const al::ActorInitInfo& rInfo) {
        const char* type = "Dummy";
        al::tryGetStringArg(&type, rInfo, "ItemType");
        return rc::getItemTypeByName(type);
    }

    int getItemTypeByName(const char* pType) {
        if (al::isEqualString(pType, "Coin")) {
            return 0;
        }
        if (al::isEqualString(pType, "Coin10")) {
            return 1;
        }
        if (al::isEqualString(pType, "CoinRandom10")) {
            return 2;
        }
        if (al::isEqualString(pType, "CoinInfinity")) {
            return 3;
        }
        if (al::isEqualString(pType, "KinokoOneUp")) {
            return 4;
        }
        if (al::isEqualString(pType, "KinokoSuper")) {
            return 5;
        }
        if (al::isEqualString(pType, "SuperBell")) {
            return 6;
        }
        if (al::isEqualString(pType, "FireFlower")) {
            return 7;
        }
        if (al::isEqualString(pType, "SuperLeaf")) {
            return 8;
        }
        if (al::isEqualString(pType, "BoomerangFlower")) {
            return 9;
        }
        if (al::isEqualString(pType, "SuperStar")) {
            return 10;
        }
        if (al::isEqualString(pType, "Ball")) {
            return 11;
        }
        if (al::isEqualString(pType, "Bomb")) {
            return 12;
        }
        if (al::isEqualString(pType, "CoinBlow")) {
            return 13;
        }
        if (al::isEqualString(pType, "GreenStar")) {
            return 14;
        }
        if (al::isEqualString(pType, "CollectItem")) {
            return 15;
        }
        if (al::isEqualString(pType, "WarpCubeLockedPiece")) {
            return 16;
        }
        if (al::isEqualString(pType, "DoubleMario")) {
            return 17;
        }
        if (al::isEqualString(pType, "KinokoBig")) {
            return 18;
        }
        if (al::isEqualString(pType, "BoxPropeller")) {
            return 19;
        }
        if (al::isEqualString(pType, "BoxKiller")) {
            return 20;
        }
        if (al::isEqualString(pType, "IllustItem")) {
            return 21;
        }
        if (al::isEqualString(pType, "AssistLeaf")) {
            return 22;
        }
        if (al::isEqualString(pType, "SuperBellSpecial")) {
            return 23;
        }
        if (al::isEqualString(pType, "CoinConcentricCircle")) {
            return 24;
        }
        if (al::isEqualString(pType, "CoinBlow30")) {
            return 25;
        }
        if (al::isEqualString(pType, "DoorKey")) {
            return 26;
        }
        if (al::isEqualString(pType, "KinokoTreasure")) {
            return 27;
        }
        if (al::isEqualString(pType, "GoalItem")) {
            return 28;
        }
        if (al::isEqualString(pType, "Shards")) {
            return 30;
        }
        if (al::isEqualString(pType, "WhiteBell")) {
            return 29;
        }

        return 0;
    }

    bool tryAppearItemPressDown(const al::LiveActor* pActor, const char* pItemName) {
        if (!al::isStep(pActor, rc::getStepAppearItemPressDown())) {
            return false;
        }

        if (pItemName != nullptr) {
            al::appearItemTiming(pActor, pItemName);
        } else {
            al::appearItem(pActor);
        }

        return true;
    }

    int getStepAppearItemPressDown() {
        return 0xE;
    }

    void killBySwitchAndAppearItem(al::LiveActor* pActor, const char* pName) {
        if (!al::isDead(pActor)) {
            pActor->kill();
            al::setAppearItemFactor(pActor, "直接攻撃", nullptr);

            if (pName != nullptr) {
                al::appearItemTiming(pActor, pName);
            } else {
                al::appearItem(pActor);
            }
        }
    }
};  // namespace rc