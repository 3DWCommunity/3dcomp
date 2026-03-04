#include "MapObj/SnowCover.hpp"
#include "Library/ActorUtil.hpp"
#include "Library/HitSensor/HitSensorKeeper.hpp"
#include "Library/Nerve/NerveSetup.hpp"
#include "System/GameDataFunction.hpp"
#include "System/GameDataHolderAccessor.hpp"
#include "Util/ProjectMsgUtil.hpp"
#include <prim/seadSafeString.h>

namespace {
    NERVE_DECL(SnowCover, Wait);
    NERVE_DECL(SnowCover, Break);
    NERVE_DECL(SnowCover, Thaw);
    NERVES_MAKE_STRUCT(SnowCover, Wait, Break, Thaw);
};  // namespace

SnowCover::SnowCover(const char* a1, const char* a2, const char* a3, al::LiveActor* pActor) : al::LiveActor(a1) {
    _148 = a2;
    _150 = a3;
    _158 = pActor;
}

void SnowCover::init(const al::ActorInitInfo& rInfo) {
    al::initActorWithArchiveName(this, rInfo, sead::SafeString(_148), _150);
    al::initNerve(this, &NrvSnowCover.Wait, 0);
    makeActorAppeared();
}

void SnowCover::respawn() {
    if (al::isDead(this)) {
        al::setNerve(this, &NrvSnowCover.Wait);
        appear();
    }
}

bool SnowCover::receiveMsg(const al::SensorMsg* pMsg, al::HitSensor* pSender, al::HitSensor* pReceiver) {
    if (!al::isNerve(this, &NrvSnowCover.Wait)) {
        return false;
    }

    if (al::isMsgPlayerFireBallAttack(pMsg)) {
        al::setNerve(this, &NrvSnowCover.Thaw);
        return true;
    }

    GameDataHolderAccessor accessor(this);
    if (GameDataFunction::isSingleMode(accessor) && _158) {
        if (al::isMsgPlayerHipDropAll(pMsg)) {
            auto sensor = _158->mHitSensorKeeper->getSensor("Body");

            if (sensor != nullptr) {
                if (al::sendMsgPlayerHipDrop(sensor, pSender, rc::tryGetMsgComboCount(pMsg))) {
                    return true;
                }
            }
        }
    }

    return false;
}

void SnowCover::tryBreak() {
    if (!al::isDead(this) && al::isNerve(this, &NrvSnowCover.Wait)) {
        al::setNerve(this, &NrvSnowCover.Break);
    }
}

void SnowCover::exeWait() {
    return;
}

void SnowCover::exeBreak() {
    if (al::isFirstStep(this)) {
        al::startAction(this, "Break");
    }

    if (al::isActionEnd(this)) {
        kill();
    }
}

void SnowCover::exeThaw() {
    if (al::isFirstStep(this)) {
        al::startAction(this, "Thaw");
    }

    if (al::isActionEnd(this)) {
        kill();
    }
}

SnowCover* SnowCoverFunction::tryCreateSnowCover(al::LiveActor* pActor, const al::ActorInitInfo& rInfo, const char* a3, bool a4, const char* a5) {
    bool isSnow = false;
    al::tryGetArg(&isSnow, rInfo, "IsSnowCover");
    if (isSnow != false) {
        auto actor = al::isSingleMode(rInfo) ? pActor : nullptr;
        SnowCover* cover = new SnowCover("雪カバー", a3, a5, actor);
        al::initCreateActorWithPlacementInfo(cover, rInfo);

        if (a4) {
            al::initSubActorKeeperNoFile(pActor, rInfo, 1);
        }

        al::registerSubActorSyncClipping(pActor, cover, false);
        return cover;
    }

    return nullptr;
}

SnowCover::~SnowCover() {
    // empty
}