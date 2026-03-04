#include "MapObj/Bird.hpp"
#include "Library/ActorUtil.hpp"
#include "Library/Math/MathUtil.hpp"
#include "Library/Nerve/NerveSetup.hpp"
#include "Library/Screen/ScreenPointTarget.hpp"
#include "Library/StageSwitch/StageSwitchFunc.hpp"
#include "Library/Thread/Functor.hpp"
#include "MapObj/DrcAssistDirectorUtil.hpp"
#include "Project/Audio/AudioSystem.hpp"

namespace {
    NERVE_DECL(Bird, Wait);
    NERVE_DECL(Bird, Turn);
    NERVE_DECL(Bird, Fly);
    NERVES_MAKE_STRUCT(Bird, Wait, Turn, Fly);
};  // namespace

/*
bool Bird::receiveMsgScreenPoint(const al::SensorMsg* pMsg, al::ScreenPointer* pPointer, al::ScreenPointTarget* pTarget) {
    sead::Vector3f v11;

    if (al::isMsgTouchAssistTrig(pMsg) && !al::isNerve(this, &NrvBird.Fly)) {
        v11 = sead::Vector3f::ez;
        sead::Vector3f* screenPos = al::getScreenPointTargetPos(pTarget);
        sead::Vector3f* hitScreenPos = al::getHitScreenPointTargetPos(pPointer);
        v11.x = screenPos->x - hitScreenPos->x;
        v11.z = screenPos->z - hitScreenPos->z;
        v11.y = 0.0f;
    }
}
    */

Bird::Bird(const char* pName) : al::LiveActor(pName) {
    // empty
}

void Bird::init(const al::ActorInitInfo& rInfo) {
    al::initActor(this, rInfo);
    al::initNerve(this, &NrvBird.Wait, 0);
    al::listenStageSwitchOnStart(this, al::Functor(this, &Bird::startFlySwitch));
    makeActorAppeared();
}

// https://decomp.me/scratch/bOav6
void Bird::exeWait() {
    if (al::isFirstStep(this)) {
        const char* a;

        if (al::isHalfProbability()) {
            a = "GroundWaitA";
        } else {
            a = "GroundWaitB";
        }
        al::startAction(this, a);
    }

    if (al::isMicInputOn(this)) {
        startFlySwitch();
    } else if (al::isActionEnd(this)) {
        al::setNerve(this, &NrvBird.Turn);
    }
}

void Bird::exeTurn() {
    if (al::isFirstStep(this)) {
        al::startAction(this, "Turn");
        f32 rand = al::getRandom(30.0f, 90.0f);
        bool h = al::isHalfProbability();
        f32 v4 = -rand;

        if (!h) {
            v4 = rand;
        }

        _144 = v4 / 12.0f;
    }

    if (al::isMicInputOn(this)) {
        startFlySwitch();
    } else {
        al::rotateQuatYDirDegree(this, _144);
        if (al::isGreaterEqualStep(this, 12)) {
            al::setNerve(this, &NrvBird.Wait);
        }
    }
}

void Bird::exeFly() {
    if (al::isFirstStep(this)) {
        al::startAction(this, "FlyWait");
    }

    al::addVelocityToDirection(this, _148, 1.3f);
    al::scaleVelocity(this, 0.97f);

    if (al::isGreaterEqualStep(this, 180)) {
        kill();
    }
}

Bird::~Bird() {
    // empty
}