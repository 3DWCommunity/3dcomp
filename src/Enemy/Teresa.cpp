#include "Enemy/Teresa.hpp"
#include "Enemy/TargetFinder.hpp"
#include "Library/ActorUtil.hpp"
#include "Library/Math/MathUtil.hpp"
#include "Library/Nerve/NerveSetup.hpp"
#include "Project/Effect/Core/EffectUtil.hpp"
#include "Util/ItemUtil.hpp"

namespace {
    NERVE_DECL(Teresa, sub_710015E040);
    NERVE_DECL(Teresa, Chase);
    NERVE_DECL(Teresa, sub_710015E090);
    NERVE_DECL(Teresa, ReturnArea);
    NERVE_DECL(Teresa, Down);
    NERVE_DECL(Teresa, DisappearOutArea);
    NERVE_DECL(Teresa, AttackHit);
    NERVE_DECL(Teresa, ReactionWait);
    NERVE_DECL(Teresa, ReactionAppear);
    NERVE_DECL(Teresa, Reaction);
    NERVE_DECL(Teresa, DamageLight);
    NERVE_DECL(Teresa, Wait);
    NERVE_DECL(Teresa, ShyStart);
    NERVE_DECL(Teresa, ShyWait);
    NERVE_DECL(Teresa, ShyEndSign);
    NERVE_DECL(Teresa, ShyEnd);

    NERVES_MAKE_STRUCT(Teresa, sub_710015E040, Chase, sub_710015E090, ReturnArea, Down, DisappearOutArea, AttackHit, ReactionWait, ReactionAppear,
                       Reaction, DamageLight, Wait, ShyStart, ShyWait, ShyEndSign, ShyEnd);
};  // namespace

static sead::Color4f qword_7101B20440;

Teresa::Teresa(const char* pName) : al::LiveActor(pName) {
    _154.x = 0.0f;
    _154.y = 0.0f;
    _154.z = 0.0f;
}

void Teresa::killBySwitch() {
    rc::killBySwitchAndAppearItem(this, nullptr);
}

void Teresa::appearBySwitch() {
    if (!al::isNerve(this, &NrvTeresa.Down)) {
        al::setRenderStateBlendColor(this, qword_7101B20440);
        _148 = 1.0f;
        al::setTrans(this, _154);
        al::startAction(this, "Appear");
        al::startAction(al::getSubActor(this, 0), "Appear");
        al::LiveActor::appear();
        al::setNerve(this, &NrvTeresa.sub_710015E040);
    }
}

void Teresa::disappearBySwitch() {
    if (!al::isNerve(this, &NrvTeresa.Down) && !al::isNerve(this, &NrvTeresa.DisappearOutArea)) {
        al::setNerve(this, &NrvTeresa.DisappearOutArea);
    }
}

void Teresa::kill() {
    al::startHitReactionDeath(this);
    al::LiveActor::kill();
}

// Teresa::control

void Teresa::attackSensor(al::HitSensor* pSender, al::HitSensor* pReceiver) {
    if (!al::isNerve(this, &NrvTeresa.sub_710015E040) && !al::isNerve(this, &NrvTeresa.Down) && !al::isNerve(this, &NrvTeresa.Reaction) &&
        !al::isNerve(this, &NrvTeresa.ReactionWait) && !al::isNerve(this, &NrvTeresa.ReactionAppear) &&
        !al::isNerve(this, &NrvTeresa.DisappearOutArea)) {
        if (al::isSensorEnemyBody(pSender) && al::isSensorEnemyBody(pReceiver)) {
            al::sendMsgPushAndKillVelocityToTarget(this, pSender, pReceiver);
        }

        if (al::isSensorEnemyAttack(pSender) && al::isSensorPlayer(pReceiver) && al::sendMsgEnemyAttack(pReceiver, pSender)) {
            al::setNerve(this, &NrvTeresa.AttackHit);
        }
    }
}

// Teresa::receiveMsg

bool Teresa::receiveMsgScreenPoint(const al::SensorMsg* pMsg, al::ScreenPointer*, al::ScreenPointTarget*) {
    if (al::isNerve(this, &NrvTeresa.Down)) {
        return false;
    }

    if (!al::isMsgTouchAssist(pMsg)) {
        return false;
    }

    _146 = 1;

    if (!al::isNerve(this, &NrvTeresa.Reaction) && !al::isNerve(this, &NrvTeresa.ReactionWait) && !al::isNerve(this, &NrvTeresa.ReactionAppear) &&
        !al::isNerve(this, &NrvTeresa.DisappearOutArea)) {
        al::setNerve(this, &NrvTeresa.Reaction);
    }

    return true;
}

void Teresa::exeShyEnd() {
    if (al::isFirstStep(this)) {
        al::startAction(this, "ShyEnd");
        al::startAction(al::getSubActor(this, 0), "ShyEnd");

        deleteShyEffect();
    }

    if (al::isActionEnd(this)) {
        sub_710015D060(mTargetFinder, mLinkAreaGroup);
    }
}

void Teresa::deleteShyEffect() {
    if (al::isEffectEmitting(this, "Shy")) {
        al::deleteEffect(this, "Shy");
    }
}

void Teresa::exeAppear() {
    if (al::isActionEnd(this)) {
        sub_710015D060(mTargetFinder, mLinkAreaGroup);
    }
}

// Teresa::exeReactionWait
// Teresa::exeReactionAppear

void Teresa::exeDisappearOutArea() {
    if (al::isFirstStep(this)) {
        al::startHitReactionDisappear(this);
        deleteShyEffect();
    }

    f32 a = al::lerpValue(al::calcNerveRate(this, 0x3C), qword_7101B20440.b, 0.0f);
    sead::Color4f color;
    color.r = qword_7101B20440.r;
    color.b = qword_7101B20440.b;
    color.a = a;
    al::setRenderStateBlendColor(this, color);
    al::setShadowIntensityUser(this, color.b * _14C, "体影");

    if (al::isGreaterEqualStep(this, 60)) {
        al::LiveActor::kill();
    }
}

void Teresa::exeAttackHit() {
    if (al::isFirstStep(this)) {
        al::startAction(this, "AttackHit");
        al::startAction(al::getSubActor(this, 0), "AttackHit");

        deleteShyEffect();

        mTargetFinder->refindTarget();
        al::LiveActor* a = mTargetFinder->_8;

        if (a != nullptr) {
            al::faceToTarget(this, al::getTrans(a));
        }
    }

    al::setVelocityZero(this);

    if (al::isActionEnd(this)) {
        sub_710015D060(mTargetFinder, mLinkAreaGroup);
    }
}

void Teresa::exeDown() {
    if (al::isFirstStep(this)) {
        al::startAction(this, "Down");
        al::startAction(al::getSubActor(this, 0), "Down");

        deleteShyEffect();
    }

    al::setVelocityZero(this);

    if (al::isActionEnd(this)) {
        al::appearItem(this);
        kill();
    }
}

Teresa::~Teresa() {
}