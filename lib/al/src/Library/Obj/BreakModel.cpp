#include "Library/Obj/BreakModel.hpp"
#include "Library/ActorUtil.hpp"
#include "Library/Nerve/NerveSetup.hpp"

namespace al {
    namespace {
        NERVE_DECL(BreakModel, Wait);
        NERVE_DECL(BreakModel, Break);
        NERVES_MAKE_STRUCT(BreakModel, Wait, Break);
    };  // namespace

    BreakModel::BreakModel(LiveActor* a1, const char* a2, const char* a3, const char* a4, const sead::Matrix34f* a5, const char* a6, bool a7)
        : LiveActor(a2) {
        _148 = a1;
        _150 = a5;
        _158 = a3;
        _160 = a6;
        _168 = a4;

        if (a7) {
            getName();
        }
    }

    void BreakModel::init(const ActorInitInfo& rInfo) {
        al::initActorWithArchiveName(this, rInfo, sead::SafeString(_158), _168);
        al::initNerve(this, &NrvBreakModel.Wait, 0);
        al::invalidateClipping(this);
        makeActorDead();
    }

    void BreakModel::appear() {
        if (_150 != nullptr) {
            al::updatePoseMtx(this, _150);
        } else {
            al::copyPose(this, _148);
        }

        if (_160 != nullptr) {
            al::startAction(this, _160);
        }

        al::setNerve(this, &NrvBreakModel.Break);
        LiveActor::makeActorAppeared();
    }

    void BreakModel::exeWait() {
        // empty
    }

    void BreakModel::exeBreak() {
        if (al::isActionEnd(this)) {
            kill();
        }
    }

    BreakModel::~BreakModel() {
        // empty
    }
};  // namespace al