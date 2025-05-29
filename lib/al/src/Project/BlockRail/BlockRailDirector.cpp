#include "Project/BlockRail/BlockRailDirector.hpp"
#include "Project/BlockRail/BlockRail.hpp"
#include "Project/BlockRail/BlockRailLink.hpp"
#include "Project/BlockRail/BlockRailRider.hpp"

namespace al {
    BlockRailDirector::BlockRailDirector() {
        mRails = new BlockRail*[0x100];
        for (int i = 0; i < mMaxRails; i++) {
            mRails[i] = nullptr;
        }
    }

    void BlockRailDirector::initAfterPlacementSceneObj(const ActorInitInfo &rInfo) {
        for (int v5 = 0; v5 < mNumRails - 1; v5++) {
            for (int v6 = v5 + 1; v6 < mNumRails; v6++) {
                al::BlockRail::tryConnect(mRails[v5], mRails[v6]);
            }
        }

        for (int i = 0; i < mNumRails; i++) {
            mRails[i]->tryCreateRailEnd(rInfo);
        }
    }

    void BlockRailDirector::registerBlockRail(BlockRail *pRail) {
        if (mNumRails < mMaxRails) {
            pRail->getName();
            mRails[mNumRails] = pRail;
            mNumRails++;
        }
    }

    bool BlockRailDirector::tryRideBlockRail(BlockRailRider *pRailRider, const sead::Vector3f &a2, const sead::Vector3f &a3) {
        f32 v13;

        for (int i = 0; i < mNumRails; i++) {
            v13 = 0.0f;
            if (mRails[i]->mRailLink->isRide(&v13, a2, a3)) {
                auto railLink = mRails[i]->mRailLink;
                f32 v11 = v13;
                f32 totalLength = railLink->getTotalLength();
                pRailRider->setRailPart(railLink, v11 * totalLength);
                return true;
            }
        }

        return false;
    }
};