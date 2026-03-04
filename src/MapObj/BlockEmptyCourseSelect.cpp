#include "MapObj/BlockEmptyCourseSelect.hpp"
#include "Library/ActorUtil.hpp"
#include "Util.hpp"

BlockEmptyCourseSelect::BlockEmptyCourseSelect(const char* pName) : al::LiveActor(pName) {
    // empty
}

void BlockEmptyCourseSelect::init(const al::ActorInitInfo& rInfo) {
    al::initActorWithArchiveName(this, rInfo, sead::SafeString("BlockEmpty"), "CourseSelect");
    makeActorAppeared();
}

bool BlockEmptyCourseSelect::receiveMsg(const al::SensorMsg* pMsg, al::HitSensor* pSender, al::HitSensor* pReceiver) {
    if (!al::isMsgPlayerUpperPunch(pMsg) || _144 != 0) {
        return false;
    }

    al::startHitReactionHit(this);
    _144 = 10;
    return false;
}

void BlockEmptyCourseSelect::control() {
    if (_144 - 1 > -1) {
        _144--;
    }
}

BlockEmptyCourseSelect::~BlockEmptyCourseSelect() {
    // empty
}