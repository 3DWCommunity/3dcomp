#include "MapObj/ItemStatePopUpFront.hpp"

ItemStatePopUpFrontParam::ItemStatePopUpFrontParam(const sead::Vector3f& a1, f32 a2, f32 a3, int a4, f32 a5, bool a6, const char* a7, bool a8,
                                                   al::HitSensor* a9)
    : _8(a7) {
    _40 = a1;
    _4C = a1;
    _58 = a2;
    _5C = a2;
    _60 = a3;
    _64 = a3;
    _68 = a4;
    _6C = a4;
    _70 = a5;
    _74 = a6;
    _75 = a8;
    _76 = 0;
    _77 = 0;
    _0 = a9;
    _78 = 0;
}

// https://decomp.me/scratch/Y4522
void ItemStatePopUpFrontParam::setDefault() {
    _40.x = 0.0f;
    _40.y = 11.0f;
    _40.z = 5.0f;
    _4C.x = 0.0f;
    _4C.y = 8.0f;
    _4C.z = 4.0f;
    _58 = 0.4f;
    _5C = 0.2f;
    _60 = 0.99f;
    _64 = 0.95f;
    _68 = 0x28;
    _6C = 0x1E;
    _70 = 0.7f;
    _74 = 1;
    _8 = "PopUp";
    _0 = nullptr;
    _75 = false;
    _76 = 0;
    _77 = 0;
    _78 = 0;
}