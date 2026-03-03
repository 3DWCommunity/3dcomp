#pragma once

#include "Library/Nerve/NerveStateBase.hpp"

namespace al {
    class ActorInitInfo;
    class HitSensor;
    class SensorMsg;
    class ScreenPointer;
};  // namespace al

class SnowCover;
class BlockEmpty;
class BlockStateHeadgear;
class BlockStateCoinTen;

class BlockStateItem : public al::ActorStateBase {
public:
    BlockStateItem(al::LiveActor*, const al::ActorInitInfo&, bool, bool, bool, bool, bool);

    virtual ~BlockStateItem();

    bool isUseStateHeadgear() const;
    bool isItemType(int) const;
    bool isUseStateCoinTen() const;
    void appearCoinRandom10();
    void appearCoin10();
    bool reset();
    void attackSensor(al::HitSensor*, al::HitSensor*);
    bool trySendMsgToUpperLowerObj(al::HitSensor*, al::HitSensor*);
    bool receiveMsg(const al::SensorMsg*, al::HitSensor*, al::HitSensor*);
    bool receiveMsgAndAppearItem(const al::SensorMsg*, al::HitSensor*);
    void validateHitSensorsForBlockPowerPunch();
    void validateHitSensorsForBlockUpperPunch();
    bool receiveMsgScreenPoint(const al::SensorMsg*, al::ScreenPointer*);
    void validateHitSensorsForBlockDrcPunch();
    bool tryAppearItem(const al::SensorMsg*, al::HitSensor*, bool);
    bool isValidAppearItmem() const;
    void colectAppearItemTiming(al::HitSensor*);
    bool tryExecAppearItemLong(const al::HitSensor*);
    BlockEmpty* getBlockEmpty() const;
    BlockEmpty* tryGetBlockEmpty() const;
    BlockStateCoinTen* tryGetBlockStateCoinTen() const;
    void setNerveEnd();
    void exeWait();
    void exeAppearItem();
    void exeCoin10();
    void exeHeadgear();
    void exeEnd();

    int mItemType;  // 0x20
    u32 _24;
    BlockEmpty* mBlockEmpty;             // 0x28
    SnowCover* mSnowCover;               // 0x30
    BlockStateCoinTen* mStateCoinTen;    // 0x38
    BlockStateHeadgear* mStateHeadGear;  // 0x40
    u32 _48;
    u32 _4C;
    u32 _50;
    u8 _54;
    u8 _55;
    u8 _56;
    u8 _57;
    u32 _58;
    u32 _5C;
    u32 _60;
    u32 _64;
    u32 _68;
    s32 _6C;
    u32 _70;
    bool mIsLong;  // 0x74
    u8 _75;
    u8 _76;
    u8 _77;
    u64 _78;
    u64 _80;
    u32 _88;
    u8 _8C;
    u8 _8D;
    u32 _90;
    u32 _94;
};