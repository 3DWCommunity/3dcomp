#pragma once

#include <math/seadVector.h>

namespace al {
    class IUseEffectKeeper;

    void emitEffectCurrentPos(IUseEffectKeeper*, const char*);
    void emitEffect(IUseEffectKeeper*, const char*, const sead::Vector3f*);
    bool isEffectExist(IUseEffectKeeper*, const char*);
    bool isEffectSnapshotCameraMode(IUseEffectKeeper*, const char*);
    bool tryEmitEffect(IUseEffectKeeper*, const char*, const sead::Vector3f*);
    void deleteEffect(IUseEffectKeeper*, const char*);
    bool tryDeleteEffect(IUseEffectKeeper*, const char*);
    bool tryDeleteEffectAndParticle(IUseEffectKeeper*, const char*);
    void deleteEffectAll(IUseEffectKeeper*);
    bool tryKillEmitterAndParticleAll(IUseEffectKeeper*);
    bool tryDeleteEmitterAndParticleAll(IUseEffectKeeper*);
    void onCalcAndDrawEffect(IUseEffectKeeper*);
    void offCalcAndDrawEffect(IUseEffectKeeper*);
    void updateEffects(IUseEffectKeeper*);
    void forceSetStopCalcAndDraw(IUseEffectKeeper*, bool);
    bool isEffectEmitting(const IUseEffectKeeper*, const char*);
    bool isEffectEmittingFully(const IUseEffectKeeper*, const char*);
    void setEffectEmitRatio(IUseEffectKeeper*, const char*, f32);
    void setEffectEmitterScale(IUseEffectKeeper*, const char*, const sead::Vector3f&);
    void setEffectScale(IUseEffectKeeper*, const char*, const sead::Vector3f&);
    void setEffectEmitterVolumeScale(IUseEffectKeeper*, const char*, const sead::Vector3f&);
    void setEffectParticleScale(IUseEffectKeeper*, const char*, f32);
};  // namespace al