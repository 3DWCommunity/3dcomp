#include "Project/BlockRail/BlockRailLink.hpp"
#include "Project/BlockRail/BlockRailShape.hpp"

namespace al {
    BlockRailLink::BlockRailLink(int a1) {
        mNextLinks = nullptr;
        mNumPrevLinks = 0;
        mNumNextLinks = 0;
        mShape = nullptr;
        mPrevLinks = nullptr;
        _20 = a1;
        _24 = 1;
        mPrevLinks = new BlockRailLink*[a1];
        mNextLinks = new BlockRailLink*[a1];

        for (int i = 0; i < _20; i++) {
            mPrevLinks[i] = nullptr;
            mNextLinks[i] = nullptr;
        }
    }

    // al::BlockRailLink::init
    // al::BlockRailLink::init

    void BlockRailLink::calcOffset(const sead::Vector3f &rOffs) {
        if (mShape != nullptr) {
            mShape->calcOffset(rOffs);
        }
    }
    
    void BlockRailLink::updateLinkedTrans(const sead::Vector3f &rOffs) {
        if (mShape != nullptr) {
            mShape->updateLinkedTrans(rOffs);
        }
    }

    void BlockRailLink::setShape(BlockRailShape *pShape) {
        mShape = pShape;
    }

    void BlockRailLink::addPrev(BlockRailLink *pLink) {
        if (mNumPrevLinks < _20) {
            mPrevLinks[mNumPrevLinks] = pLink;
            mNumPrevLinks++;
        }
    }

    void BlockRailLink::addNext(BlockRailLink *pLink) {
        if (mNumNextLinks < _20) {
            mNextLinks[mNumNextLinks] = pLink;
            mNumNextLinks++;
        }
    }

    bool BlockRailLink::isRide(f32 *a1, const sead::Vector3f &a2, const sead::Vector3f &a3) const {
        if (_24) {
            return mShape->isRide(a1, a2, a3);
        }

        return false;
    }

    f32 BlockRailLink::getTotalLength() const {
        return mShape->getTotalLength();
    }

    void BlockRailLink::calcPosAndDir(sead::Vector3f *pPos, sead::Vector3f *pDir, f32 a3) const {
        mShape->calcPos(pPos, a3);
        mShape->calcDir(pDir, a3);
    }

    void BlockRailLink::calcPos(sead::Vector3f *pPos, f32 a2) const {
        mShape->calcPos(pPos, a2);
    }

    void BlockRailLink::calcDir(sead::Vector3f *pDir, f32 a2) const {
        return mShape->calcDir(pDir, a2);
    }

    void BlockRailLink::calcNearestParam(sead::Vector3f *a1, f32 *a2, const sead::Vector3f &a3) const {
        mShape->calcNearestParam(a1, a2, a3);
    }

    bool BlockRailLink::isTerminate() const {
        return mShape->isTerminate();
    }

    BlockRailLink* BlockRailLink::getPrevLink(int idx) const {
        return mPrevLinks[idx];
    }

    BlockRailLink* BlockRailLink::getNextLink(int idx) const {
        return mNextLinks[idx];
    }

    bool BlockRailLink::isPrevLink(const BlockRailLink *pLink) const {
        if (pLink == nullptr) {
            return false;
        }
        
        for (int i = 0; i < mNumPrevLinks; i++) {
            if (mPrevLinks[i] == pLink) {
                return true;
            }
        }
        
        return false;
    }

    bool BlockRailLink::isNextLink(const BlockRailLink *pLink) const {
        if (pLink == nullptr) {
            return false;
        }
        
        for (int i = 0; i < mNumNextLinks; i++) {
            if (mNextLinks[i] == pLink) {
                return true;
            }
        }
        
        return false;
    }

    // al::BlockRailLink::tryConnect
};