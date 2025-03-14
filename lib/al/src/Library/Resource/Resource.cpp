#include "Library/Resource/Resource.hpp"
#include "Library/File/FileUtil.hpp"
#include "Project/Base/StringUtil.hpp"
#include <heap/seadHeapMgr.h>

const sead::DirectoryEntry cEntries[0x1000];
static const char* cPatchFiles[0x1B] = {
    "FieryRoll1",
    "FieryRollsPartA",
    "FieryRollsPartABossLod",
    "GigaBell",
    "RaidonSurfFur",
    "BalanceTruckFireStep",
    "LargeHubStepABossLod",
    "NekoDisaster",
    "NekoParentDisaster",
    "PlessieRampJumboStepBossLod",
    "PlessieRampJumboStep",
    "PlessieTunnelWallsStep",
    "DarkBowser",
    "DoorLock",
    "BlackSun",
    "KoopaJrFur",
    "CollectItemEmpty",
    "OblongSkateWheelBBossLod",
    "OblongSkateWheelLongABossLod",
    "OblongSkateWheelLongBBossLod",
    "OblongSkateStepCBossLod",
    "OblongSkateWheelABossLod",
    "BunbunFur",
    "BunbunChameleonFur",
    "TimerGate",
    "KameckFur",
    "MarioClimbGigaTail"
};

namespace al {
    Resource::Resource(const sead::SafeString &rRes) 
        : mArchive(nullptr), mDevice(nullptr), mResName(rRes) {

        mHeap = sead::HeapMgr::sInstancePtr->getCurrentHeap();
        _B0 = 0;
        mPatchRes = nullptr;
        _C0 = 0;
        mArchive = al::loadArchive(rRes);
        mDevice = new sead::ArchiveFileDevice(mArchive);
    }

    Resource::Resource(const sead::SafeString &rRes, sead::ArchiveRes *pArchiveRes)
        : mArchive(nullptr), mDevice(nullptr), mResName(rRes) {

        mHeap = sead::HeapMgr::sInstancePtr->getCurrentHeap();
        _B0 = 0;
        mPatchRes = nullptr;
        _C0 = 0;
        mArchive = pArchiveRes;
        mDevice = new sead::ArchiveFileDevice(mArchive);
    }

    bool Resource::loadPatchData() {
        for(s32 i = 0; i < 28; i++) {
            // strip the "ObjectData/" portion out of the input string
            if (al::isEqualString(cPatchFiles[i], &mResName.cstr()[0xB])) {
                al::StringTmp<256> patchFile("%s_p",mResName.cstr());
                mPatchRes = new Resource(patchFile);
                return true;
            }
        }

        return false;
    }

    bool Resource::isExistFile(const sead::SafeString& rString) const {
        bool res = false;
        mDevice->tryIsExistFile(&res, rString);

        if (res) {
            return true;
        }
        else {
            if (mPatchRes != nullptr) {
                res = mPatchRes->isExistFile(rString);
            }
        }

        return res;
    }

    // al::Resource::isExistByml

    u32 Resource::getSize() const {
        return mArchive->getRawSize();
    }

    // https://decomp.me/scratch/B4Wvu
    u32 Resource::getEntryNum(const sead::SafeString &rName) const {
        sead::DirectoryHandle dir_handle;
        
        if (mDevice->tryOpenDirectory(&dir_handle, rName)) {
            u32 entries_read = 0;
            mDevice->tryReadDirectory(&entries_read, &dir_handle, (sead::DirectoryEntry*)cEntries, 0x1000);
            mDevice->tryCloseDirectory(&dir_handle);
            return entries_read;
        }
    
        return 0;
    }

    // https://decomp.me/scratch/Zb82a
    void Resource::getEntryName(sead::BufferedSafeString *pStr, const sead::SafeString &rName, u32 a3) const {
        sead::DirectoryHandle dir_handle;
        mDevice->tryOpenDirectory(&dir_handle, rName);
        u32 entries_read = 0;
        mDevice->tryReadDirectory(&entries_read, &dir_handle, (sead::DirectoryEntry*)cEntries, 0x1000);
        mDevice->tryCloseDirectory(&dir_handle);
        pStr->format("%s", cEntries[a3].name.cstr());
    }

    u32 Resource::getFileSize(const sead::SafeString &rFile) const {
        auto device = mDevice;
        u32 size = 0;
        device->tryGetFileSize(&size, rFile);
        return size;
    }

    /*
    const void* Resource::getFile(const sead::SafeString &rFile) const {
        const Resource* cur = mPatchRes;

        if (cur != nullptr) {
            while (cur->isExistFile(rFile)) {
                cur = cur->mPatchRes;
            }
        }

        return cur->mArchive->getFile(rFile);
    }
    */
};