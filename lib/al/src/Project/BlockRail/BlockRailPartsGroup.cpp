#include "Project/BlockRail/BlockRailPartsGroup.hpp"
#include "Project/BlockRail/BlockRailParts.hpp"

namespace al {
    BlockRailPartsGroup::BlockRailPartsGroup() = default;

    /*
    void BlockRailPartsGroup::init(const ActorInitInfo &rInfo) {
        mNumRailParts = al::calcLinkChildNum(rInfo, "Parts");

        if (mNumRailParts != 0) {
            mRailParts = new BlockRailParts*[mNumRailParts];

            for (int i = 0; i < mNumRailParts; i++) {
                mRailParts[i] = new BlockRailParts(al::getLinksActorDisplayName(rInfo, "Parts", i));
                al::initLinksActor(mRailParts[i], rInfo, "Parts", i);
            }

            for (int i = 0; i < mNumRailParts; i++) {
                for (int j = 0; j < mNumRailParts; j++) {
                    BlockRailParts::tryConnect(mRailParts[j], mRailParts[i]);
                }
            }
        }
    }*/

    void BlockRailPartsGroup::calcOffset(const sead::Vector3f &rVec) {
        for (int i = 0; i < mNumRailParts; i++) {
            mRailParts[i]->calcOffset(rVec);
        }
    }

    void BlockRailPartsGroup::updateLinkedTrans(const sead::Vector3f &rVec) {
        for (int i = 0; i < mNumRailParts; i++) {
            mRailParts[i]->updateLinkedTrans(rVec);
        }
    }

    void BlockRailPartsGroup::active() {
        for (int i = 0; i < mNumRailParts; i++) {
            mRailParts[i]->appear();
        }
    }

    void BlockRailPartsGroup::specialActive(u32 idx) {
        mRailParts[idx]->appear();
    }

    void BlockRailPartsGroup::deactive() {
        for (int i = 0; i < mNumRailParts; i++) {
            mRailParts[i]->makeActorDead();
        }
    }

    BlockRailParts* BlockRailPartsGroup::getParts(int idx) const {
        return mRailParts[idx];
    }
}