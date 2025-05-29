#include "Library/ActorUtil.hpp"
#include "Library/Actor/ActorSensorController.hpp"
#include "Library/HitSensor/HitSensor.hpp"
#include "Library/HitSensor/HitSensorKeeper.hpp"
#include "Library/LiveActor/LiveActor.hpp"

namespace al {

    SENSOR_MSG_CHECK(EnemyAttackKnockDown);
    SENSOR_MSG_CHECK(EnemyAttackBoomerang);
    SENSOR_MSG_CHECK(EnemyRouteDokanAttack);
    SENSOR_MSG_CHECK(EnemyRouteDokanFire);
    SENSOR_MSG_CHECK(Explosion);
    SENSOR_MSG_CHECK(ExplosionCollide);

    s32 getHitSensorNum(const LiveActor* pActor) {
        return pActor->mHitSensorKeeper->mSensorCount;
    }

    // void setHitSensorSort(LiveActor *pActor, const char *pSensorName, const SensorSortCmpFuncBase *)

    void setHitSensorPosPtr(LiveActor* pActor, const char* pSensorName, const sead::Vector3f* pPosPtr) {
        pActor->mHitSensorKeeper->getSensor(pSensorName)->setFollowPosPtr(pPosPtr);
    }

    HitSensor* getHitSensor(const LiveActor* pActor, const char* pSensorName) {
        return pActor->mHitSensorKeeper->getSensor(pSensorName);
    }

    void setHitSensorMtxPtr(LiveActor* pActor, const char* pSensorName, const sead::Matrix34f* pMtx) {
        pActor->mHitSensorKeeper->getSensor(pSensorName)->setFollowMtxPtr(pMtx);
    }

    void setHitSensorJointMtx(LiveActor* pActor, const char* pSensorName, const char* pJointName) {
        pActor->mHitSensorKeeper->getSensor(pSensorName)
            ->setFollowMtxPtr(getJointMtxPtr(pActor, pJointName));
    }

    const sead::Matrix34f* getHitSensorFollowMtx(HitSensor* pSensor) {
        return pSensor->mFollowPosMtx;
    }

    HitSensor* getHitSensor(const LiveActor* pActor, s32 sensorIdx) {
        return pActor->mHitSensorKeeper->getSensor(sensorIdx);
    }

    void setSensorRadius(LiveActor* pActor, const char* pSensorName, f32 radius) {
        HitSensor* sensor = pActor->mHitSensorKeeper->getSensor(pSensorName);
        sensor->mRadius = radius;
    }

    void setSensorRadius(LiveActor* pActor, s32 sensorIdx, f32 radius) {
        HitSensor* sensor = pActor->mHitSensorKeeper->getSensor(sensorIdx);
        sensor->mRadius = radius;
    }

    void setSensorRadius(LiveActor* pActor, f32 radius) {
        HitSensor* sensor = pActor->mHitSensorKeeper->getSensor(nullptr);
        sensor->mRadius = radius;
    }

    f32 getSensorRadius(const LiveActor* pActor, const char* pSensorName) {
        return pActor->mHitSensorKeeper->getSensor(pSensorName)->mRadius;
    }

    f32 getSensorRadius(const LiveActor* pActor, s32 sensorIdx) {
        return pActor->mHitSensorKeeper->getSensor(sensorIdx)->mRadius;
    }

    f32 getSensorRadius(const LiveActor* pActor) {
        return pActor->mHitSensorKeeper->getSensor(nullptr)->mRadius;
    }

    void setSensorFollowPosOffset(LiveActor* pActor, const char* pSensorName,
                                const sead::Vector3f& rOffset) {
        getHitSensor(pActor, pSensorName)->mFollowPosOffset.set(rOffset);
    }

    void setSensorFollowPosOffset(LiveActor* pActor, s32 sensorIdx, const sead::Vector3f& rOffset) {
        getHitSensor(pActor, sensorIdx)->mFollowPosOffset.set(rOffset);
    }

    void setSensorFollowPosOffset(LiveActor* pActor, const sead::Vector3f& rOffset) {
        getHitSensor(pActor, nullptr)->mFollowPosOffset.set(rOffset);
    }

    sead::Vector3f* getSensorFollowPosOffset(const LiveActor* pActor, const char* pSensorName) {
        return &pActor->mHitSensorKeeper->getSensor(pSensorName)->mFollowPosOffset;
    }

    sead::Vector3f* getSensorFollowPosOffset(const LiveActor* pActor, s32 sensorIdx) {
        return &pActor->mHitSensorKeeper->getSensor(sensorIdx)->mFollowPosOffset;
    }

    sead::Vector3f* getSensorFollowPosOffset(const LiveActor* pActor) {
        return &pActor->mHitSensorKeeper->getSensor(nullptr)->mFollowPosOffset;
    }

    ActorSensorController* createActorSensorController(LiveActor* pActor, const char* pName) {
        return new ActorSensorController(pActor, pName);
    }

    void setSensorRadius(ActorSensorController* pController, f32 radius) {
        pController->setSensorRadius(radius);
    }

    void setSensorFollowPosOffset(ActorSensorController* pController, const sead::Vector3f& rOffs) {
        pController->setSensorFollowPosOffset(rOffs);
    }

    f32 getOriginalSensorRadius(const ActorSensorController* pController) {
        return pController->mSensorRadius;
    }

    const sead::Vector3f* getOriginalSensorFollowPosOffset(const ActorSensorController* pController) {
        return &pController->mFollowPosOffs;
    }

    void resetActorSensorController(ActorSensorController* pController) {
        pController->resetActorSensorController();
    }
}  // namespace al
