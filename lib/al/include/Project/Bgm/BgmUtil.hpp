#pragma once

namespace al {
    class IUseAudioKeeper;

    bool tryStopAllBgm(const IUseAudioKeeper*, int);
};  // namespace al