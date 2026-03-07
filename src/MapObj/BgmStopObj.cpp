#include "MapObj/BgmStopObj.hpp"
#include "Library/ActorUtil.hpp"
#include "Library/Nerve/NerveSetup.hpp"
#include "Library/Thread/Functor.hpp"
#include "Project/Bgm/BgmUtil.hpp"

namespace {
    NERVE_DECL(BgmStopObj, Wait);
    NERVE_DECL(BgmStopObj, Stop);
    NERVES_MAKE_STRUCT(BgmStopObj, Wait, Stop);
};  // namespace

BgmStopObj::BgmStopObj(const char* pName) : al::LiveActor(pName) {
    // empty
}

void BgmStopObj::init(const al::ActorInitInfo& rInfo) {
    al::initActorSceneInfo(this, rInfo);
    al::initActorPoseTRMSV(this);
    al::initActorSRT(this, rInfo);
    al::initStageSwitch(this, rInfo);
    al::initExecutorWatchObj(this, rInfo);
    al::initActorAudioKeeperWithout3D(this, rInfo, nullptr, nullptr);
    al::initActorClipping(this, rInfo);

    if (!al::tryGetArg(&mFadeOutFrameNum, rInfo, "FadeOutFrameNum")) {
        mFadeOutFrameNum = 0;
    }

    al::invalidateClipping(this);

    if (al::listenStageSwitchOnStart(this, al::Functor(this, &BgmStopObj::start))) {
        al::initNerve(this, &NrvBgmStopObj.Wait, 0);
    }

    makeActorAppeared();
}

void BgmStopObj::start() {
    al::setNerve(this, &NrvBgmStopObj.Stop);
}

void BgmStopObj::exeWait() {
    // empty
}

void BgmStopObj::exeStop() {
    if (al::isFirstStep(this)) {
        al::tryStopAllBgm(this, mFadeOutFrameNum);
        kill();
    }
}

BgmStopObj::~BgmStopObj() {
    // empty
}