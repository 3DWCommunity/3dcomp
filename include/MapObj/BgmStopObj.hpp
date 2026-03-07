#pragma once

#include "Library/LiveActor/LiveActor.hpp"

class BgmStopObj : public al::LiveActor {
public:
    BgmStopObj(const char*);

    virtual ~BgmStopObj();
    virtual void init(const al::ActorInitInfo&);

    void start();
    void exeWait();
    void exeStop();

    int mFadeOutFrameNum = 0;  // 0x144
};