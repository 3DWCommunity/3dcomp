#pragma once

#include "Library/LiveActor/LiveActor.hpp"

class LighthouseSimple : public al::LiveActor {
public:
    LighthouseSimple(const char*);

    virtual ~LighthouseSimple();
    virtual void init(const al::ActorInitInfo&);
    virtual void initAfterPlacement();
    virtual bool receiveMsg(const al::SensorMsg*, al::HitSensor*, al::HitSensor*);

    void setPhaseColor();

    al::LiveActor* mInkActor = nullptr;        // 0x148
    al::LiveActor* mFlingPoleActor = nullptr;  // 0x150
    int _158 = -1;
};