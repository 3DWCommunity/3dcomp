#include "Library/MapObj/FixMapParts.hpp"
#include "Library/ActorUtil.hpp"
#include "Library/Connector/MtxConnector.hpp"
#include "Library/LiveActor/LiveActorFunc.hpp"
#include "Library/Play/Placement/PlacementFunction.hpp"

namespace al {
    FixMapParts::FixMapParts(const char* pName) : LiveActor(pName) {}

    void FixMapParts::initWithSuffix(const ActorInitInfo& rInfo, const char* pName) {
        al::initMapPartsActor(this, rInfo, pName, 0);

        bool needSwitch = false;

        if (mActorPoseKeeper == nullptr) {
            al::initActorPoseTQSV(this);
            needSwitch = !al::trySyncStageSwitchAppear(this);
        } else {
            needSwitch = !al::trySyncStageSwitchAppear(this);
        }

        if (needSwitch)
            al::trySyncStageSwitchKill(this);

        bool arg = false;
        bool argGet = al::tryGetArg(&arg, rInfo, "IsConnectCollision");

        if (arg && argGet)
            mConnector = al::createMtxConnector(this);
    }

    void FixMapParts::init(const ActorInitInfo& rInfo) {
        initWithSuffix(rInfo, nullptr);
    }

    void FixMapParts::initAfterPlacement() {
        LiveActor::initAfterPlacement();

        if (mConnector != nullptr)
            al::attachMtxConnectorToCollision(mConnector, this, false);
    }

    void FixMapParts::appear() {
        LiveActor::appear();

        if (mModelKeeper != nullptr)
            al::tryStartAction(this, "Appear");
    }

    void FixMapParts::control() {
        if (mConnector != nullptr)
            al::connectPoseTrans(this, mConnector, al::getConnectBaseTrans(mConnector));
    }

    void FixMapParts::updateLinkedTrans(const sead::Vector3f& rTrans) {
        alLiveActorFunction::forceUpdateTrans(this, rTrans, true);
    }

    bool FixMapParts::receiveMsg(const SensorMsg* msg, HitSensor* self, HitSensor* other) {
        if (al::isMsgAskSafetyPoint(msg))
            return true;

        if (al::isMsgShowModel(msg)) {
            al::showModelIfHide(this);
            return true;
        }

        if (!al::isMsgHideModel(msg))
            return al::isMsgSink(msg);

        al::hideModelIfShow(this);
        return true;
    }
};
