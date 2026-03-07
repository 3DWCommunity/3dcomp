#include "Library/Model/RumbleCalculator.hpp"

namespace al {
    RumbleCalculator::RumbleCalculator(f32 a1, f32 a2, f32 a3, u32 a4) {
        _8 = a4;
        _C = a4;
        _10 = 0;
        _14 = 0;
        _18 = 0;
        _1C = a1;
        _20 = a2;
        _24 = a3;
    }

    void RumbleCalculator::start(u32 a1) {
        if (a1 != 0) {
            _C = a1;
        }

        _8 = 0;
        _10 = 0;
        _14 = 0;
        _18 = 0;
    }

    // al::RumbleCalculator::calc

    void RumbleCalculator::reset() {
        _8 = _C;
        _10 = 0;
        _14 = 0;
        _18 = 0;
    }

};  // namespace al