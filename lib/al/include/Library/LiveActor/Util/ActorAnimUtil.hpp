#pragma once

#include <basis/seadTypes.h>

namespace al {
    class LiveActor;

    void startMclAnim(LiveActor*, const char*);
    bool tryStartMclAnimIfExist(LiveActor*, const char*);
    void setMclAnimFrameAndStop(LiveActor*, f32);

    f32 getVisAnimFrameMax(const LiveActor*, const char*);
    void setVisAnimFrame(const LiveActor*, f32);
    void setVisAnimFrameRate(const LiveActor*, f32);
    void setVisAnimFrameAndStop(LiveActor*, f32);
    void setVisAnimFrameAndStopEnd(LiveActor*);
    void startVisAnimAndSetFrameAndStop(LiveActor*, const char*, f32);

    void startSklAnim(LiveActor*, const char*);
    void startSklAnimInterpole(LiveActor*, const char*, const char*);
    bool tryStartSklAnimIfExist(LiveActor*, const char*);
    bool isSklAnimExist(const LiveActor*, const char*);

    f32 getMtpAnimFrameMax(const LiveActor*);
    f32 getMtpAnimFrameMax(const LiveActor*, const char*);
    void setMtpAnimFrameAndStop(LiveActor*, f32);
    void setMtpAnimFrameAndStopEnd(LiveActor*);
    void startMclAnim(LiveActor*, const char*);
    bool tryStartMclAnimIfExist(LiveActor*, const char*);
    bool isMclAnimExist(const LiveActor*, const char*);
    bool tryStartMclAnimIfNotPlaying(LiveActor*, const char*);
    bool isMclAnimPlaying(const LiveActor*, const char*);
    void clearMclAnim(LiveActor*);
    bool isMclAnimExist(const LiveActor*);
    bool isMclAnimEnd(const LiveActor*);
    bool isMclAnimOneTime(const LiveActor*, const char*);
    bool isMclAnimOneTime(const LiveActor*);
};  // namespace al