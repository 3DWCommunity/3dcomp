#include "Project/BlockRail/BlockRailRider.hpp"
#include "Project/BlockRail/BlockRailLink.hpp"
#include "Project/BlockRail/BlockRailRouteSelecter.hpp"
#include "Library/Math/MathUtil.hpp"

namespace al {
    BlockRailLink* BlockRailRider::selectRoute(BlockRailLink *a1, BlockRailLink *a2) const {
        if (!a2->_24) {
            return a1;
        }

        if (a1 != nullptr) {
            if (mSelecter != nullptr) {
                if (mSelecter->compareBlockRailRoute(this, a2, a1)) {
                    return a2;
                }
                else {
                    return a1;
                }
            }
            else {
                return a1;
            }
        }
        else {
            return a2;
        }
    }

    bool BlockRailRider::calcDir(sead::Vector3f *pDir) const {
        if (mRailLink != nullptr) {
            f32 totalLength = mRailLink->getTotalLength();
            f32 v6;
            if (al::isNearZero(totalLength, 0.001f)) {
                v6 = 0.0f;
            }
            else {
                v6 = _10 / totalLength;
            }

            mRailLink->calcDir(pDir, v6);
            if (!_14) {
                pDir->negate();
            }

            return true;
        }

        return false;
    }

    void BlockRailRider::setRailPart(BlockRailLink *pLink, f32 a2) {
        mRailLink = pLink;
        _10 = a2;
        _14 = 1;
    }
    
    void BlockRailRider::setRouteSelecter(BlockRailRouteSelecter *pSelecter) {
        mSelecter = pSelecter;
    }

    void BlockRailRider::reverse() {
        _14 ^= 1;
    }

    bool BlockRailRider::isRide() const {
        return mRailLink != nullptr;
    }
};