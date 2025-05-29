#include "Project/BlockRail/BlockRail.hpp"
#include "Project/BlockRail/BlockRailLink.hpp"
#include "Library/ActorUtil.hpp"
#include "Project/Matrix/MatrixUtil.hpp"
#include "Library/Yaml/ByamlIter.hpp"
#include "Library/Play/Placement/PlacementFunction.hpp"

namespace al {
    BlockRail::BlockRail(const char *pName) : LiveActor(pName) {

    }

    void BlockRail::init(const ActorInitInfo &rInfo) {
        al::initMapPartsActor(this, rInfo, nullptr, 0);
        auto res = al::getMapPartsResourceYaml(rInfo, "BlockRailParam");
        ByamlIter iter(res);
        mRailLink = new BlockRailLink(2);
        mRailLink->init(rInfo, iter);
        iter.tryGetStringByKey(&mEndModel, "EndModel");
        al::tryGetArg(&mRailColor, rInfo, "RailColor");
        al::registerBlockRail(this);
        al::trySyncStageSwitchAppearAndKill(this);

        if (al::isExistModel(this) && al::tryStartMclAnimIfExist(this, "RailColor")) {
            al::setMclAnimFrameAndStop(this, mRailColor);
        }   
    }

    void BlockRail::makeActorAppeared() {
        LiveActor::makeActorAppeared();
        mRailLink->_24 = 1;
        if (_150 != nullptr) {
            _150->makeActorAppeared();
        }

        if (_158 != nullptr) {
            _158->makeActorAppeared();
        }
    }

    void BlockRail::makeActorDead() {
        LiveActor::makeActorDead();
        mRailLink->_24 = 0;
        if (_150 != nullptr) {
            _150->makeActorDead();
        }

        if (_158 != nullptr) {
            _158->makeActorDead();
        }
    }

    void BlockRail::tryConnect(BlockRail *a1, BlockRail *a2) {
        al::BlockRailLink::tryConnect(a1->mRailLink, a2->mRailLink, 10.0f);
    }

    void BlockRail::tryCreateRailEnd(const al::ActorInitInfo &rInfo) {
        sead::Vector3f pos, dir;
        if (!mRailLink->isTerminate()) {
            if (mRailLink->mNumPrevLinks != 0) {
                if (mRailLink->mNumNextLinks != 0) {
                    return;
                }
                
                mRailLink->calcPosAndDir(&pos, &dir, 1.0f);
                createRailEnd(rInfo, pos, dir, &_158);
                return;
            }

            mRailLink->calcPosAndDir(&pos, &dir, 0.0f);
            createRailEnd(rInfo, pos, -dir, &_150);
            if (mRailLink->mNumNextLinks == 0) {
                mRailLink->calcPosAndDir(&pos, &dir, 1.0f);
                createRailEnd(rInfo, pos, dir, &_158);
                return;
            }
        }
    }
    
    void BlockRail::createRailEnd(const ActorInitInfo &rInfo, const sead::Vector3f &rPos, const sead::Vector3f &rDir, LiveActor **pActor) {
        if (mEndModel != nullptr) {
            ActorInitInfo info;
            info.initViewIdHostActor(rInfo, this);
            auto railEmptyActor = new LiveActor("ブロックレール空終端");
            if (rInfo._78) {
                al::addToHostActorClipping(railEmptyActor, this);
            }

            al::initActorWithArchiveName(railEmptyActor, info, mEndModel, nullptr);
            sead::Vector3f up;
            al::calcUpDir(&up, this);
            sead::Matrix34f upFrontPos;
            al::makeMtxUpFrontPos(&upFrontPos, up, rDir, rPos);
            al::updatePoseMtx(railEmptyActor, &upFrontPos);

            if (al::isExistModel(this) && al::tryStartMclAnimIfExist(railEmptyActor, "RailColor")) {
                al::setMclAnimFrameAndStop(railEmptyActor, mRailColor);
            }

            if (al::isAlive(this)) {
                railEmptyActor->appear();

                if (pActor == nullptr) {
                    return;
                }
            }
            else {
                railEmptyActor->kill();
                if (pActor == nullptr) {
                    return;
                }
            }

            *pActor = railEmptyActor;
        }
    }

    BlockRail::~BlockRail() {
        
    }
};