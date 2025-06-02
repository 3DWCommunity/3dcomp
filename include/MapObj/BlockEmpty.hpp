#pragma once

#include "Library/LiveActor/LiveActor.hpp"

class BlockEmpty : public al::LiveActor {
public:
    BlockEmpty(const char *, const char *);

    virtual ~BlockEmpty();
    virtual void init(const al::ActorInitInfo &);
    virtual void updateLinkedTrans(const sead::Vector3f &);
    virtual bool receiveMsg(const al::SensorMsg *, al::HitSensor *, al::HitSensor *);

    void exeWait();
    void onConnectRailBlock();

    s16 _144 = 0;
    s32 _148 = 0;
    sead::Vector3f _14C = sead::Vector3f::zero;
    const char* _158 = nullptr;
};