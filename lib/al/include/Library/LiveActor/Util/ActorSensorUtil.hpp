#pragma once

#include <prim/seadRuntimeTypeInfo.h>

namespace al {
    class HitSensor;
    class LiveActor;

    class SensorMsg {
        SEAD_RTTI_BASE(SensorMsg)
    };

    #define SENSOR_MSG_CLASS(name)                                      \
    class SensorMsg##name : public SensorMsg {                          \
        SEAD_RTTI_OVERRIDE(SensorMsg##name, SensorMsg)                  \
    };

    #define SENSOR_MSG_CHECK(name)                                      \
    bool isMsg##name(const SensorMsg* pMsg) {                           \
        return sead::IsDerivedFrom<SensorMsg##name>(pMsg);              \
    }

    void setSensorRadius(LiveActor *, const char *, f32);
    void setSensorRadius(LiveActor *, f32);
    f32 getSensorRadius(const LiveActor *, const char *);
    f32 getSensorRadius(const LiveActor *, int);
    f32 getSensorRadius(const LiveActor *);

    bool isSensorSimple(const HitSensor*);
    void updateHitSensorsAll(LiveActor*);
    bool isMySensor(const HitSensor*, LiveActor*);

    HitSensor* getHitSensor(const LiveActor*, const char*);

    bool isMsgPlayerInvincibleTouch(const SensorMsg *);

    bool isMsgFloorTouch(const SensorMsg*);

    bool isMsgAskSafetyPoint(const SensorMsg*);

    bool isMsgHideModel(const SensorMsg*);

    bool isMsgSink(const SensorMsg*);

    bool isMsgShowModel(const SensorMsg*);

    SENSOR_MSG_CLASS(EnemyAttackKnockDown);
    SENSOR_MSG_CLASS(EnemyAttackBoomerang);
    SENSOR_MSG_CLASS(EnemyRouteDokanAttack);
    SENSOR_MSG_CLASS(EnemyRouteDokanFire);
    SENSOR_MSG_CLASS(Explosion);
    SENSOR_MSG_CLASS(ExplosionCollide);
    SENSOR_MSG_CLASS(PlayerKouraAttack);
    SENSOR_MSG_CLASS(KickKouraAttack);
    SENSOR_MSG_CLASS(KickKouraAttackCollide);
    SENSOR_MSG_CLASS(PlayerAttackTrample);
    SENSOR_MSG_CLASS(PlayerAttackHipDrop);
    SENSOR_MSG_CLASS(PlayerAttackObjHipDrop);
    SENSOR_MSG_CLASS(PlayerAttackObjHipDropReflect);
    SENSOR_MSG_CLASS(PlayerAttackObjHipDropHighJump);
    SENSOR_MSG_CLASS(PlayerAttackStatueDrop);
    SENSOR_MSG_CLASS(PlayerAttackObjStatueDrop);
    SENSOR_MSG_CLASS(PlayerAttackObjStatueDropReflect);
    SENSOR_MSG_CLASS(PlayerAttackInvincibleAttack);
    SENSOR_MSG_CLASS(PlayerInvincibleTouch);
    SENSOR_MSG_CLASS(PlayerAttackTailAttack);

}  // namespace al
