#pragma once

class ComboCounter;

namespace al {
    class LiveActor;
    class ComboCounter;
};  // namespace al

namespace rc {
    al::ComboCounter* createExplosionComboCounter(const al::LiveActor*);

    al::ComboCounter* getExplosionComboCounterAndNextIndex(const al::LiveActor*);
};  // namespace rc