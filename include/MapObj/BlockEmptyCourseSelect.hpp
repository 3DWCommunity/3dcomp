#pragma once

#include "Library/LiveActor/LiveActor.hpp"

class BlockEmptyCourseSelect : public al::LiveActor {
public:
    BlockEmptyCourseSelect(const char*);

    virtual ~BlockEmptyCourseSelect();
    virtual void init(const al::ActorInitInfo&);
    virtual bool receiveMsg(const al::SensorMsg*, al::HitSensor*, al::HitSensor*);
    virtual void control();

    s32 _144 = 0;
};