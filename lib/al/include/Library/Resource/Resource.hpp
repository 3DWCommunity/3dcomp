#pragma once

#include <basis/seadTypes.h>
#include <prim/seadSafeString.hpp>
#include <resource/seadArchiveRes.h>
#include "filedevice/seadArchiveFileDevice.h"

namespace al {
class Resource {
public:
    Resource(const sead::SafeString &);
    Resource(const sead::SafeString &, sead::ArchiveRes *);

    bool loadPatchData();
    bool isExistFile(const sead::SafeString &) const;
    bool isExistByml(const char *) const;
    u32 getSize() const;
    u32 getEntryNum(const sead::SafeString &) const;
    void getEntryName(sead::BufferedSafeString *, const sead::SafeString &, u32) const;
    u32 getFileSize(const sead::SafeString &) const;
    const u8* getByml(const sead::SafeString &) const;
    void* getFile(const sead::SafeString &) const;

    // ...

    void* getOtherFile(const sead::SafeString&, u32*) const;
    const char* getArchiveName() const;

    sead::ArchiveRes* mArchive;                 // 0x00
    sead::ArchiveFileDevice* mDevice;           // 0x08
    sead::FixedSafeString<0x80> mResName;       // 0x10
    sead::Heap* mHeap;                          // 0xA8
    u64 _B0;
    Resource* mPatchRes;                        // 0xB8
    u64 _C0;
};
}  // namespace al
