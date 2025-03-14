#pragma once

#include <resource/seadArchiveRes.h>

namespace al {
    sead::ArchiveRes* loadArchive(const sead::SafeString &);
};