#pragma once

namespace al {
    class LiveActor;
    class ScreenPointer;
};  // namespace al

namespace rc {
    bool tryFindDrcTouchActor(const al::LiveActor*, const al::ScreenPointer*);
};