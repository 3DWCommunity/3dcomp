#include "Library/Rail/RailPart.hpp"

namespace al {
    RailPart::RailPart() {

    }

    // RailPart::init

    void RailPart::setUp(sead::Vector3f &a1, sead::Vector3f &a2) {
        _14 = a1;
        _20 = a2;
    }

    void RailPart::setAccel(f32 a1, f32 a2) {
        _2C = a1;
        _30 = a2;
    }

    void RailPart::getAccels(f32 *a1, f32* a2) {
        *a1 = _2C;
        *a2 =_30;
    }

    void RailPart::setAngleS(f32 angle) {
        _34 = angle;
        _3C = 1;
    }

    void RailPart::setAngleE(f32 angle) {
        _38 = angle;
        _3D = 1;
    }

    bool RailPart::getAngleS(f32 *angle) {
        if (!_3C) {
            return false;
        }

        *angle = _34;
        return true;
    }

    bool RailPart::getAngleE(f32 *angle) {
        if (!_3D) {
            return false;
        }

        *angle = _38;
        return true;
    }
};