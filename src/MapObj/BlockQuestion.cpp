#include "MapObj/BlockQuestion.hpp"
#include "Library/ActorUtil.hpp"
#include "Library/Nerve/NerveSetup.hpp"
#include "MapObj/BlockEmpty.hpp"
#include "MapObj/BlockStateItem.hpp"
#include "Util/ItemUtil.hpp"

namespace {
    NERVE_DECL(BlockQuestion, State);
    NERVE_DECL(BlockQuestion, Empty);
    NERVES_MAKE_STRUCT(BlockQuestion, State, Empty);
};  // namespace

BlockQuestion::BlockQuestion(const char* pName) : al::LiveActor(pName) {
    // empty
}

void BlockQuestion::init(const al::ActorInitInfo& rInfo) {
    bool isLong = al::isObjectName(rInfo, "BlockQuestionLong");
    bool isSingle = al::isSingleMode(rInfo);
    al::initActorSuffix(this, rInfo, rc::getBlockSuffixName(rInfo, isSingle));
    al::initNerve(this, &NrvBlockQuestion.State, 1);
    bool isForceAppearCoin = false;
    al::tryGetArg(&isForceAppearCoin, rInfo, "IsForceAppearBoxCoin");
    mStateItem = new BlockStateItem(this, rInfo, isLong, false, false, false, isForceAppearCoin);
    al::initNerveState(this, mStateItem, &NrvBlockQuestion.State, "BlockItem");
    f32 shadowLength = -1.0f;
    al::tryGetArg(&shadowLength, rInfo, "ShadowLength");

    if (shadowLength > 0.0f) {
        al::setShadowDropLength(this, shadowLength, "シャドウマスク");
    }

    bool isExpClipping = false;
    al::tryGetArg(&isExpClipping, rInfo, "IsExpandClippingShadowLength");
    if (isExpClipping) {
        al::tryExpandClippingByShadowLength(this, &_150);
    }

    makeActorAppeared();
}

void BlockQuestion::respawn() {
    if (!al::isNerve(this, &NrvBlockQuestion.State) || al::isDead(this)) {
        if (mStateItem->reset()) {
            al::validateCollisionParts(this);
            al::validateHitSensors(this);
            al::setNerve(this, &NrvBlockQuestion.State);
            if (al::isDead(this)) {
                makeActorAppeared();
            }
        } else if (!al::isDead(this)) {
            makeActorDead();
        }
    }
}

void BlockQuestion::attackSensor(al::HitSensor* pSender, al::HitSensor* pReceiver) {
    mStateItem->attackSensor(pSender, pReceiver);
}

bool BlockQuestion::receiveMsg(const al::SensorMsg* pMsg, al::HitSensor* pSender, al::HitSensor* pReceiver) {
    if (al::isMsgLaserAttack(pMsg)) {
        return false;
    }

    return mStateItem->receiveMsg(pMsg, pSender, pReceiver);
}

bool BlockQuestion::receiveMsgScreenPoint(const al::SensorMsg* pMsg, al::ScreenPointer* pPointer, al::ScreenPointTarget* pTarget) {
    return mStateItem->receiveMsgScreenPoint(pMsg, pPointer);
}

void BlockQuestion::onConnectRailBlock() {
    _144 = 1;
    al::setShadowFixed(this, false);
    mStateItem->_77 = 1;
}

bool BlockQuestion::isLong() const {
    return mStateItem->mIsLong;
}

BlockStateItem* BlockQuestion::getBlockStateItem() const {
    return mStateItem;
}

void BlockQuestion::exeState() {
    if (al::updateNerveState(this)) {
        if (_144) {
            al::hideModel(this);
            al::setNerve(this, &NrvBlockQuestion.Empty);
        } else {
            kill();
        }
    }
}

void BlockQuestion::exeEmpty() {
    if (al::isFirstStep(this)) {
        al::invalidateHitSensors(this);
        al::invalidateCollisionParts(this);
    }

    al::copyPose(mStateItem->getBlockEmpty(), this);
}

BlockQuestion::~BlockQuestion() {
    // empty
}