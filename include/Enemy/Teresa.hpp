#pragma once

#include "Library/LiveActor/LiveActor.hpp"

namespace al {
    class AreaObjGroup;
};

class FlyerStateChase;
class FlyerStateFindPlayer;
class TargetFinder;
class FlyerStateReturnArea;

class Teresa : public al::LiveActor {
public:
    Teresa(const char*);

    virtual ~Teresa();
    virtual void init(const al::ActorInitInfo&);
    virtual void kill();
    virtual void attackSensor(al::HitSensor*, al::HitSensor*);
    virtual bool receiveMsg(const al::SensorMsg*, al::HitSensor*, al::HitSensor*);
    virtual bool receiveMsgScreenPoint(const al::SensorMsg*, al::ScreenPointer*, al::ScreenPointTarget*);
    virtual void control();

    void killBySwitch();
    void appearBySwitch();
    void disappearBySwitch();
    void exeAppear();
    void sub_710015D060(TargetFinder*, al::AreaObjGroup*);
    void exeWait();
    void exeFindPlayer();
    void exeChase();
    void exeReturnArea();
    void exeShyStart();
    void exeShyWait();
    bool isPlayerSight();
    void exeShyEndSign();
    void exeShyEnd();
    void deleteShyEffect();
    void exeDamageLight();
    void exeReaction();
    void exeReactionWait();
    void exeReactionAppear();
    void exeDisappearOutArea();
    void exeAttackHit();
    void exeDown();
    void exesub_710015E040();
    void exesub_710015E090();

    u8 _144 = 0;
    u8 _145 = 0;
    u8 _146 = 0;
    u8 _147 = 0;
    f32 _148 = 1.0f;
    f32 _14C = 1.0f;
    u32 _150 = 0;
    sead::Vector3f _154;
    FlyerStateChase* mStateChase = nullptr;            // 0x160
    FlyerStateFindPlayer* mStateFindPlayer = nullptr;  // 0x168
    FlyerStateReturnArea* mStateReturnArea = nullptr;  // 0x170
    TargetFinder* mTargetFinder = nullptr;             // 0x178
    al::AreaObjGroup* mLinkAreaGroup = nullptr;        // 0x180
    al::HitSensor* _188 = nullptr;
};