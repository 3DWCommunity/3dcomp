#pragma once

#include "Library/LiveActor/LiveActor.hpp"

class SnowCover : public al::LiveActor {
public:
    SnowCover(const char*);

    virtual ~SnowCover();
    virtual void init(const al::ActorInitInfo&);
    virtual void respawn();
    virtual bool receveMsg(al::SensorMsg*, al::HitSensor*, al::HitSensor*);
};

namespace SnowCoverFunction {
    SnowCover* tryCreateSnowCover(al::LiveActor*, const al::ActorInitInfo&, const char*, bool, const char*);
};  // namespace SnowCoverFunction