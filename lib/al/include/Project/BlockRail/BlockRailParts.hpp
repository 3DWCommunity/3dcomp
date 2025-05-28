#pragma once

#include "Library/LiveActor/LiveActor.hpp"
#include "Library/Yaml/ByamlIter.hpp"

namespace al {
    class BlockRailLink;
    struct PlacementInfo;

    class BlockRailParts : public LiveActor {
    public:
        BlockRailParts(const char *);

        virtual ~BlockRailParts();
        virtual void init(const ActorInitInfo &);
        virtual void appear();
        virtual void updateLinkedTrans(const sead::Vector3f &);
        virtual void startFarLod();
        virtual void startEndLod();

        void initRailLink(const ActorInitInfo &);
        void calcOffset(const sead::Vector3f &);
        ActorInitInfo* getInitInfo() const;
        void initRailLink();
        void initRailLink(const ByamlIter &);
        BlockRailLink* getLink(int) const;
        static void tryConnect(BlockRailParts *, BlockRailParts *);
        void setIsHideModel(bool);

        BlockRailLink** mLinks;                     // 0x148
        s32 mNumLinks;                              // 0x150
        u32 _154;
        const char* mModelSuffix;                   // 0x158
        ActorInitInfo* mActorInfo;                  // 0x160
        const PlacementInfo* mPlacementInfo;        // 0x168
        bool _170;
        sead::Vector3f _174;
    };
};