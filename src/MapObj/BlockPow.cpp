#include "MapObj/BlockPow.hpp"
#include "MapObj/BlockEmpty.hpp"
#include "Library/Nerve/NerveSetup.hpp"
#include "Library/Nerve/NerveUtil.hpp"
#include "Library/ActorUtil.hpp"

namespace {
    NERVE_DECL(BlockPow, Wait);
    NERVE_DECL(BlockPow, Reaction);
    NERVE_DECL(BlockPow, WaitEnd);
    NERVE_DECL(BlockPow, Empty);
    NERVES_MAKE_STRUCT(BlockPow, Wait, Reaction, WaitEnd, Empty);
};

const sead::Color4f cLightColor = sead::Color4f(2.5f, 2.5f, 1.0f, 1.0f);
const f32 cSensorRadius[2] = { 900.0f, 600.0f };

BlockPow::BlockPow(const char *pName) : al::LiveActor(pName) {

}

void BlockPow::onConnectRailBlock() {
    _170 = 1;
    al::setShadowFixed(this, false);
    if (mIsAppearEmpty) {
        mEmptyBlock->onConnectRailBlock();
    }
}

bool BlockPow::updateSensor() {
    f32 radius = cSensorRadius[_171 == 0];
    f32 sensorRadius = al::getSensorRadius(this, "Explosion");
    if (radius <= sensorRadius) {
        return false;
    }

    f32 newRadius = 10.0f;
    if (!_171) {
        newRadius = 15.0f;
    }
    al::setSensorRadius(this, "Explosion", sensorRadius + newRadius);
    return true;
}

void BlockPow::requestLightExplosion() {
    al::requestPrePassLightColor(this, mIsWideRangeLight ? "爆発[広範囲]" : "爆発", cLightColor);
}

void BlockPow::exeWait() {
    if (al::isFirstStep(this)) {
        al::startAction(this, "Wait");
    }
}

BlockPow::~BlockPow() {

}