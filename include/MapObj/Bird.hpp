#pragma once

#include "Library/LiveActor/LiveActor.hpp"

class Bird : public al::LiveActor {
public:
    Bird(const char*);

    virtual ~Bird();
    virtual void init(const al::ActorInitInfo&);
    virtual bool receiveMsg(const al::SensorMsg*, al::HitSensor*, al::HitSensor*);
    virtual bool receiveMsgScreenPoint(const al::SensorMsg*, al::ScreenPointer*, al::ScreenPointTarget*);

    void startFlySwitch();
    void startFly(const sead::Vector3f&);
    void exeWait();
    void exeTurn();
    void exeFly();

    f32 _144 = 0;
    sead::Vector3f _148 = sead::Vector3f::ez;
};