#pragma once

#include <math/seadMatrix.h>

namespace al {
    class LiveActor;

    void tryInitFixedModelGpuBuffer(LiveActor*);

    bool isHideModel(const LiveActor*);

    void hideModel(LiveActor*);
    void showModel(LiveActor*);

    void showModelIfHide(LiveActor*);
    void hideModelIfShow(LiveActor*);

    bool isExistModel(const LiveActor*);

    void setNeedSetBaseMtxAndCalcAnimFlag(LiveActor*, bool);

    sead::Matrix34f* getJointMtxPtr(const LiveActor*, const char*);

    void updateMaterialCodeWater(LiveActor*);

    void setRenderStateBlendColor(LiveActor*, const sead::Color4f&);

    void setCustomRenderEnable(LiveActor*, bool);
    void setEnableDepthTest(LiveActor*, bool);
    void setEnableDepthWrite(LiveActor*, bool);

}  // namespace al
