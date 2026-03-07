#include "Util/ItemUtil.hpp"
#include "Library/ActorUtil.hpp"
#include "Library/Item/AcquireItemFunc.hpp"
#include "Library/LiveActor/LiveActor.hpp"
#include "Library/Play/Placement/PlacementUtil.hpp"
#include "Project/Base/StringUtil.hpp"

namespace rc {
    void initItemByHostInfo(al::LiveActor* pActor, const al::ActorInitInfo& rInfo, int a3) {
        pActor->initItemKeeper(a3);
        rc::addItemByHostInfo(pActor, rInfo, nullptr, nullptr);
    }

      void addItemByHostInfo(al::LiveActor* pActor, const al::ActorInitInfo& rInfo, const char* a3, const char* a4) {
        const char* type = "Dummy";
        al::tryGetStringArg(&type, rInfo, "ItemType");

        const char* str = "コインx1[自動取得]";

        if (al::isEqualString(type, "Coin")) {
            str = "コインx1[自動取得]";
        } else if (al::isEqualString(type, "Coin10")) {
            str = "コインx1[自動取得＆高速出現]";
        } else if (al::isEqualString(type, "CoinRandom10")) {
            str = "コインx1[飛出し出現]";
        } else if (al::isEqualString(type, "CoinInfinity")) {
            str = "コインx1[自動取得＆高速出現]";
        } else if (al::isEqualString(type, "Coinx3")) {
            str = "コインx3[自動取得]";
        } else if (al::isEqualString(type, "KinokoOneUp")) {
            str = "1UPキノコ";
        } else if (al::isEqualString(type, "KinokoSuper")) {
            str = "スーパーキノコ";
        } else if (al::isEqualString(type, "SuperBell")) {
            str = "スーパーベル";
        } else if (al::isEqualString(type, "FireFlower")) {
            str = "ファイアフラワー";
        } else if (al::isEqualString(type, "SuperLeaf")) {
            str = "スーパーこのは";
        } else if (al::isEqualString(type, "BoomerangFlower")) {
            str = "ブーメランフラワー";
        } else if (al::isEqualString(type, "SuperStar")) {
            str = "スーパースター";
        } else if (al::isEqualString(type, "Ball")) {
            str = "ボール";
        } else if (al::isEqualString(type, "Bomb")) {
            str = "バクダン";
        } else if (al::isEqualString(type, "CoinBlow")) {
            str = "コインx1";
        } else if (al::isEqualString(type, "GreenStar")) {
            str = "グリーンスター";
        } else if (al::isEqualString(type, "DoubleMario")) {
            str = "ダブルマリオ";
        } else if (al::isEqualString(type, "KinokoBig")) {
            str = "巨大キノコ";
        } else if (al::isEqualString(type, "AssistLeaf")) {
            str = "無敵このは";
        } else if (al::isEqualString(type, "SuperBellSpecial")) {
            str = "まねきネコベル";
        } else if (al::isEqualString(type, "CoinConcentricCircle")) {
            str = "同心円コイン";
        } else if (al::isEqualString(type, "CoinBlow30")) {
            str = "コインx30";
        } else if (al::isEqualString(type, "DoorKey")) {
            str = "DoorKey";
        } else if (al::isEqualString(type, "KinokoTreasure")) {
            str = "KinokoTreasure";
        } else if (al::isEqualString(type, "GoalItem")) {
            str = "GoalItem";
        } else if (al::isEqualString(type, "WhiteBell")) {
            str = "WhiteBell";
        } else if (al::isEqualString(type, "Shards")) {
            str = "Shards";
        }

        al::addItem(pActor, rInfo, str, a3, a4, 0);
    }  

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