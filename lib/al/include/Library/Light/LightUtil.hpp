#pragma once

#include <gfx/seadColor.h>

namespace al {
    class LiveActor;

    void requestPrePassLightColor(const LiveActor *, const char *, const sead::Color4f &);
    void requestPrePassLightColor(const LiveActor *, const char *, f32);
    void requestPrePassLightColor(const LiveActor *, const char *, const char *, f32);
};