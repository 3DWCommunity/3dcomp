#include "MapObj/LighthouseSimple.hpp"
#include "Library/Actor/ActorInitInfo.hpp"
#include "Library/ActorUtil.hpp"
#include "Library/Play/Placement/PlacementInfo.hpp"
#include "Project/Play/Placement/PlacementHolder.hpp"

LighthouseSimple::LighthouseSimple(const char* pName) : al::LiveActor(pName) {
    // empty
}

// https://decomp.me/scratch/qrECp
void LighthouseSimple::init(const al::ActorInitInfo& rInfo) {
    al::initActorWithArchiveName(this, rInfo, sead::SafeString("Lighthouse"), nullptr);
    mInkActor = new al::LiveActor("LighthouseInk");
    al::initActorWithArchiveName(mInkActor, rInfo, "LighthouseInk", nullptr);
    al::invalidateHitSensors(mInkActor);
    makeActorAppeared();
    mInkActor->makeActorDead();
    al::invalidateCollisionParts(this);
    al::invalidateCollisionParts(mInkActor);
    mFlingPoleActor = new al::LiveActor("FlingPoleFlag");
    al::initActorWithArchiveName(mFlingPoleActor, rInfo, sead::SafeString("FlingPoleFlag"), nullptr);

    sead::Vector3f trans;
    sead::Vector3f rotate;

    if (al::calcLinkChildNum(rInfo, "FlingPole") == 1) {
        al::getChildLinkTR(&trans, &rotate, rInfo, "FlingPole", 0);
    } else {
        al::getRotate(&rotate, *rInfo.mPlacementInfo);
        trans = al::getTrans(this);
        trans.add(0.0f, 2439.2f, 0.0f);
    }

    al::resetPosition(mFlingPoleActor, trans, rotate);
    mFlingPoleActor->makeActorDead();
}

// LighthouseSimple::initAfterPlacement

void LighthouseSimple::setPhaseColor() {
    s32 unk = mPlacementHolder->_20;
    f32 v2 = 2.0f;
    f32 v4;

    if (unk < 9) {
        v2 = 1.0f;
    }

    if (unk <= 4) {
        v4 = 0.0f;

    } else {
        v4 = v2;
    }

    if (al::tryStartMclAnimIfExist(this, "PhaseColor")) {
        al::setMclAnimFrameAndStop(this, v4);
    }

    if (al::tryStartVisAnimIfExist(this, "PhaseColor")) {
        al::setVisAnimFrameAndStop(this, v4);
    }

    if (al::tryStartMtpAnimIfExist(this, "PhaseColor")) {
        al::setMtpAnimFrameAndStop(this, v4);
    }

    if (mInkActor != nullptr) {
        if (al::tryStartMclAnimIfExist(mInkActor, "PhaseColor")) {
            al::setMclAnimFrameAndStop(mInkActor, v4);
        }

        if (al::tryStartVisAnimIfExist(mInkActor, "PhaseColor")) {
            al::setVisAnimFrameAndStop(mInkActor, v4);
        }

        if (al::tryStartMtpAnimIfExist(mInkActor, "PhaseColor")) {
            al::setMtpAnimFrameAndStop(mInkActor, v4);
        }
    }
}

bool LighthouseSimple::receiveMsg(const al::SensorMsg* pMsg, al::HitSensor*, al::HitSensor*) {
    return al::isMsgPlayerDisregard(pMsg);
}

LighthouseSimple::~LighthouseSimple() {
    // empty
}