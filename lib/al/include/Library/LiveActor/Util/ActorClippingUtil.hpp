#pragma once

namespace al {
    class ClippingJudge;
    class LiveActor;

    void addToHostActorClipping(LiveActor *, const LiveActor *);

    ClippingJudge* getClippingJudge(LiveActor*);

    bool isClipped(const LiveActor*);

    bool isInvalidCliping(const LiveActor*);
    void invalidateClipping(LiveActor*);
    void validateClipping(LiveActor*);
    void onDrawClipping(LiveActor*);
    void offDrawClipping(LiveActor*);
    void onUseCameraClippingPos(LiveActor*);
    void offUseCameraClippingPos(LiveActor*);
};
