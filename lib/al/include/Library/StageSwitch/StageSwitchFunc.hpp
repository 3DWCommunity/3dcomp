#pragma once

namespace al {
    class FunctorBase;
    class IUseStageSwitch;
    class StageSwitchDirector;
    struct PlacementInfo;
    class ActorInitInfo;

    void initStageSwitch(IUseStageSwitch *, const ActorInitInfo &);
    void initStageSwitch(IUseStageSwitch*, StageSwitchDirector*, const PlacementInfo&);
    bool tryInitStageSwitch(IUseStageSwitch *, StageSwitchDirector *, const PlacementInfo &);
    bool isValidStageSwitch(const IUseStageSwitch *, const char *);
    bool isOnStageSwitch(const IUseStageSwitch *, const char *);
    void onStageSwitch(IUseStageSwitch *, const char *);
    void offStageSwitch(IUseStageSwitch *, const char *);
    bool tryOnStageSwitch(IUseStageSwitch *, const char *);
    bool tryOffStageSwitch(IUseStageSwitch *, const char *);
    bool tryOnStageSwitchInstant(IUseStageSwitch *, const char *);
    bool tryOffStageSwitchInstant(IUseStageSwitch *, const char *);
    bool isSameStageSwitch(const IUseStageSwitch *, const IUseStageSwitch *, const char *);
    int findSwitchNo(const IUseStageSwitch *, const char *);
    bool isUsingSwitchNo(const IUseStageSwitch *, int);
    bool isValidSwitchAppear(const IUseStageSwitch *);
    bool isOnSwitchAppear(const IUseStageSwitch *);
    bool isValidSwitchKill(const IUseStageSwitch *);
    bool isValidSwitchDeadOn(const IUseStageSwitch *);
    void onSwitchDeadOn(IUseStageSwitch *);
    void offSwitchDeadOn(IUseStageSwitch *);
    bool tryOnSwitchDeadOn(IUseStageSwitch *);

    bool listenStageSwitchOnOffAppear(IUseStageSwitch*, const FunctorBase&, const FunctorBase&);
    bool listenStageSwitchOnKill(IUseStageSwitch*, const FunctorBase&);
    bool listenStageSwitchOnOff(IUseStageSwitch*, const char*, const FunctorBase&, const FunctorBase&);
}  // namespace al
