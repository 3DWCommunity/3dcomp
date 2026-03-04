#pragma once

#include "Library/LiveActor/LiveActor.hpp"

namespace al {
    class BreakModel : public LiveActor {
    public:
        BreakModel(LiveActor*, const char*, const char*, const char*, const sead::Matrix34f*, const char*, bool);

        virtual ~BreakModel();
        virtual void init(const ActorInitInfo&);
        virtual void appear();

        void exeWait();
        void exeBreak();

        LiveActor* _148;
        const sead::Matrix34f* _150;
        const char* _158;
        const char* _160;
        const char* _168;
    };
};  // namespace al