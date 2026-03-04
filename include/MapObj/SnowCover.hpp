#pragma once

#include "Library/LiveActor/LiveActor.hpp"

class SnowCover : public al::LiveActor {
public:
    SnowCover(const char*, const char*, const char*, al::LiveActor*);

    virtual ~SnowCover();
    virtual void init(const al::ActorInitInfo&);
    virtual void respawn();
    virtual bool receiveMsg(const al::SensorMsg*, al::HitSensor*, al::HitSensor*);

    void tryBreak();
    void exeWait();
    void exeBreak();
    void exeThaw();

    const char* _148;
    const char* _150;
    al::LiveActor* _158;
};

namespace SnowCoverFunction {
    SnowCover* tryCreateSnowCover(al::LiveActor*, const al::ActorInitInfo&, const char*, bool, const char*);
};  // namespace SnowCoverFunction