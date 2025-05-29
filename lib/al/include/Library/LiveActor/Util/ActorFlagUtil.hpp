#pragma once

namespace al {
    class LiveActor;

    bool isAlive(const LiveActor*);
    bool isDead(const LiveActor*);
    bool isDeadAlive(const LiveActor*);
    bool isCountAsAlive(LiveActor*);
    bool isNoCollide(const LiveActor*);

    

    bool isHideModel(const LiveActor*);
};