#pragma once

namespace al {
    class LiveActor;
    class MtxConnector;

    void connectPoseQT(LiveActor*, const MtxConnector*);

    void attachMtxConnectorToCollision(MtxConnector*, const LiveActor*, bool);
};  // namespace al