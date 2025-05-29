#pragma once

#include "Library/LiveActor/LiveActor.hpp"

namespace al {
    class BlockRailLink;

    class BlockRail : public LiveActor {
    public:
        BlockRail(const char *);    

        virtual ~BlockRail();
        virtual void init(const ActorInitInfo &);
        virtual void makeActorAppeared();
        virtual void makeActorDead();

        void tryCreateRailEnd(const ActorInitInfo &);
        void createRailEnd(const ActorInitInfo &, const sead::Vector3f &, const sead::Vector3f &, LiveActor **);
        
        static void tryConnect(BlockRail *, BlockRail *);

        BlockRailLink* mRailLink = nullptr;         // 0x148
        LiveActor* _150 = nullptr;
        LiveActor* _158 = nullptr;
        const char* mEndModel = nullptr;            // 0x160
        int mRailColor = 0;                         // 0x168
    };

    void registerBlockRail(BlockRail *);
    bool tryRideBlockRail(const LiveActor *, const sead::Vector3f &, const sead::Vector3f &);
};