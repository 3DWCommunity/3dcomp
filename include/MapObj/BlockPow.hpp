#pragma once

#include "Library/LiveActor/LiveActor.hpp"

class BlockEmpty;
class SnowCover;

namespace al {
    class ComboCounter;
};

class BlockPow : public al::LiveActor {
public:
    BlockPow(const char *);

    virtual ~BlockPow();
    virtual void init(const al::ActorInitInfo &);
    virtual void respawn();
    virtual void attackSensor(al::HitSensor *, al::HitSensor *);
    virtual bool receiveMsg(const al::SensorMsg *, al::HitSensor *, al::HitSensor *);
    virtual bool receiveMsgScreenPoint(const al::SensorMsg *, al::ScreenPointer *, al::ScreenPointTarget *);

    void appearBySwitch();
    void killBySwitch();
    void startExplosion(bool);
    void onConnectRailBlock();
    bool updateSensor();
    void requestLightExplosion();
    void exeWait();
    void exeReaction();
    void exeWaitEnd();
    void exeEmpty();

    BlockEmpty* mEmptyBlock = nullptr;                  // 0x148
    SnowCover* mSnowCover = nullptr;                    // 0x150
    al::ComboCounter* mComboCounter = nullptr;          // 0x158
    s32 mControlUserId = -1;                            // 0x160
    sead::Vector3f _164 = sead::Vector3f::zero;
    u8 _170 = 0;
    u8 _171 = 0;
    bool mIsWideRangeLight = false;                     // 0x172
    bool mIsAppearEmpty = true;                         // 0x173
    u8 _174 = 0;
};