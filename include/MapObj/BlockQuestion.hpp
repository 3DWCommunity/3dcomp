#pragma once

#include "Library/LiveActor/LiveActor.hpp"

class BlockStateItem;

class BlockQuestion : public al::LiveActor {
public:
    BlockQuestion(const char*);

    virtual ~BlockQuestion();
    virtual void init(const al::ActorInitInfo&);
    virtual void respawn();
    virtual void attackSensor(al::HitSensor*, al::HitSensor*);
    virtual bool receiveMsg(const al::SensorMsg*, al::HitSensor*, al::HitSensor*);
    virtual bool receiveMsgScreenPoint(const al::SensorMsg*, al::ScreenPointer*, al::ScreenPointTarget*);

    void onConnectRailBlock();
    bool isLong() const;
    BlockStateItem* getBlockStateItem() const;
    void exeState();
    void exeEmpty();

    u8 _144 = 0;
    BlockStateItem* mStateItem = nullptr;  // 0x148
    sead::Vector3f _150 = sead::Vector3f::zero;
};