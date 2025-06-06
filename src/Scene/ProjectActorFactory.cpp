#include "Scene/ProjectActorFactory.hpp"

#include "Project/BlockRail/BlockRail.hpp"

const al::NameToCreator<al::CreationFuncPtr> cCreateTable[0x1CB] = {
    { "AllDeadWatcher", nullptr },
    { "DisasterBlockDeadWatcher", nullptr },
    { "AssistSlideMapParts", nullptr },
    { "AssistSlideMapPartsGroup", nullptr },
    { "BalanceTruck", nullptr },
    { "Ball", nullptr },
    { "BallGimmick", nullptr },
    { "BallSnow", nullptr },
    { "BallYarn", nullptr },
    { "BallNeko", nullptr },
    { "BgmPlayObj", nullptr },
    { "BgmStopObj", nullptr },
    { "BgmRegionChanger", nullptr },
    { "Bird", nullptr },
    { "BlockAssistLeaf", nullptr },
    { "BlockBrick", nullptr },
    { "BlockBrickBig", nullptr },
    { "BlockBrickBreakable", nullptr },
    { "BlockBrickBreakableCourseSelect", nullptr },
    { "BlockChoiceWatcher", nullptr },
    { "BlockEmpty", nullptr },
    { "BlockEmptyCourseSelect", nullptr },
    { "BlockHard", nullptr },
    { "BlockHardLaserOnly", nullptr },
    { "BlockPow", nullptr },
    { "BlockQuestion", nullptr },
    { "BlockQuestionCourseSelect", nullptr },
    { "BlockRoulette", nullptr },
    { "BlockRail", al::createActorFunction<al::BlockRail> },
    { "BlockRailMover", nullptr },
    { "BlockSlot", nullptr },
    { "BlockSwitch", nullptr },
    { "BlockTransparent", nullptr },
    { "BobsledDashPanel", nullptr },
    { "Bomb", nullptr },
    { "BombBound", nullptr },
    { "BombBoundGenerator", nullptr },
    { "BombBoundQuickGenerator", nullptr },
    { "BombHei", nullptr },
    { "BombHeiLauncher", nullptr },
    { "Bonze", nullptr },
    { "BoomerangBros", nullptr },
    { "BoomerangFlower", nullptr },
    { "BossBunretsu", nullptr },
    { "BossGorobon", nullptr },
    { "BossWackun", nullptr },
    { "BoxCoin", nullptr },
    { "BoxKiller", nullptr },
    { "BoxKillerLauncher", nullptr },
    { "BoxKuribo", nullptr },
    { "BoxLight", nullptr },
    { "BreakMapParts", nullptr },
    { "BreakMapPartsBomb", nullptr },
    { "BreakMapPartsSand", nullptr },
    { "BreakMapPartsGiant", nullptr },
    { "Bubble", nullptr },
    { "Bull", nullptr },
    { "Bunbun", nullptr },
    { "Bush", nullptr },
    { "Byugo", nullptr },
    { "CameraInSwitchOnAreaWatcher", nullptr },
    { "CameraLookAtPoint", nullptr },
    { "CameraRailHolder_RS", nullptr },
    { "CameraRailObserver", nullptr },
    { "CameraWall", nullptr },
    { "Candlestand", nullptr },
    { "CandlestandWatcher", nullptr },
    { "CatGull", nullptr },
    { "CheckPoint", nullptr },
    { "CheckpointFlag", nullptr },
    { "ChikaChikaBlockWatcher", nullptr },
    { "ChikuwaBlock", nullptr },
    { "ChorobonColony", nullptr },
    { "ChorobonCubeHolder", nullptr },
    { "ChorobonHolder", nullptr },
    { "ClimbHandle", nullptr },
    { "ClimbHandleMapParts", nullptr },
    { "ClockMapParts", nullptr },
    { "CloudBonusLauncher", nullptr },
    { "Coin", nullptr },
    { "CoinBlowConcentric", nullptr },
    { "CoinBlowGenerator", nullptr },
    { "CoinChameleon", nullptr },
    { "CoinChameleonCourseSelect", nullptr },
    { "CoinCirclePlacement", nullptr },
    { "CoinCollectWatcher", nullptr },
    { "CoinConcentricCircle", nullptr },
    { "CoinCourseSelect", nullptr },
    { "CoinFallGenerator", nullptr },
    { "CoinFalls", nullptr },
    { "CoinLine", nullptr },
    { "CoinRail", nullptr },
    { "CoinRedRing", nullptr },
    { "CoinRing", nullptr },
    { "CoinStack", nullptr },
    { "CoinStackMoving", nullptr },
    { "CollectRingHolder", nullptr },
    { "CollisionSearchObj", nullptr },
    { "ConveyerMapParts", nullptr },
    { "ConveyorMapParts", nullptr },
    { "CourseSelectBgmEventController", nullptr },
    { "CourseSelectCloud", nullptr },
    { "CourseSelectDokan", nullptr },
    { "CourseSelectDokanHide", nullptr },
    { "CourseSelectMiniature", nullptr },
    { "CourseSelectNode", nullptr },
    { "CourseSelectRhythmObject", nullptr },
    { "CourseSelectRocket", nullptr },
    { "CourseSelectRouteDokan", nullptr },
    { "CourseSelectWall", nullptr },
    { "CourseSelectWorldWarpDokan", nullptr },
    { "Crab", nullptr },
    { "Crawler", nullptr },
    { "CrawlerGenerator", nullptr },
    { "CubeMapController", nullptr },
    { "DarkBowser", nullptr },
    { "DarkBowserLaserIndicator", nullptr },
    { "DashPanel", nullptr },
    { "DestructableMapParts", nullptr },
    { "DisasterFixMapParts", nullptr },
    { "DisasterFixedMapParts", nullptr },
    { "DemoEventGateKeeperChecker", nullptr },
    { "DemoAnimatic", nullptr },
    { "DemoCutscene", nullptr },
    { "DemoKoopaW7", nullptr },
    { "DemoObjBase", nullptr },
    { "DemoOpeningSwitch", nullptr },
    { "DemoStartPosition", nullptr },
    { "DemoTimerStageSwitchController", nullptr },
    { "DisasterModeController", nullptr },
    { "DisasterSpike", nullptr },
    { "DisasterSpikeBouncy", nullptr },
    { "DirectionalLightRequester", nullptr },
    { "Dokan", nullptr },
    { "DoorKey", nullptr },
    { "DoorLock", nullptr },
    { "DokanUpsideDown", nullptr },
    { "DokanWorldWarp", nullptr },
    { "Donketsu", nullptr },
    { "Dossun", nullptr },
    { "DoubleMario", nullptr },
    { "EchoBlockMapParts", nullptr },
    { "EffectObj", nullptr },
    { "EffectObjBattleArenaBunBun", nullptr },
    { "EffectObjFollowCamera", nullptr },
    { "EnemyGenerator", nullptr },
    { "EnterCatMarioMiddleViewRocket", nullptr },
    { "FallMapParts", nullptr },
    { "FairyHouseIllustItemWatcher", nullptr },
    { "FairyMii", nullptr },
    { "FairyNpc", nullptr },
    { "FairyNpcWithGlasses", nullptr },
    { "FairyPrincess", nullptr },
    { "FallingPillar", nullptr },
    { "FieryRotateMapParts", nullptr },
    { "FireBarRoot", nullptr },
    { "FireBros", nullptr },
    { "FireFlower", nullptr },
    { "Fireworks", nullptr },
    { "FireworksController", nullptr },
    { "FireworksEffectObj", nullptr },
    { "FishColony", nullptr },
    { "FixMapParts", nullptr },
    { "FixedMapParts", nullptr },
    { "FlipCircusDoorA", nullptr },
    { "FlingPole", nullptr },
    { "FlipPanel", nullptr },
    { "FloaterMapParts", nullptr },
    { "FloatingTerrain", nullptr },
    { "FloatingIslandRailPart", nullptr },
    { "FlowerCat", nullptr },
    { "FlowerCactus", nullptr },
    { "FlowerRhythm", nullptr },
    { "FlyOverCamera", nullptr },
    { "FogRequester", nullptr },
    { "FortressGoal", nullptr },
    { "FrameOutChecker", nullptr },
    { "Fugumannen", nullptr },
    { "Gabon", nullptr },
    { "Gamane", nullptr },
    { "GateKeeperChecker", nullptr },
    { "GateMapParts", nullptr },
    { "Gesso", nullptr },
    { "GeneratorBox", nullptr },
    { "GhostPlayerHolder", nullptr },
    { "GiantTouchBreakMapParts", nullptr },
    { "GigaBellItem", nullptr },
    { "GoalBonusGameBlockSlot", nullptr },
    { "GoalDoor", nullptr },
    { "GoalItem", nullptr },
    { "GoalItemWatcher", nullptr },
    { "GoalPedestal", nullptr },
    { "GoalPole", nullptr },
    { "GoalPoleRunaway", nullptr },
    { "GodRayRequester", nullptr },
    { "Gondola", nullptr },
    { "Gong", nullptr },
    { "Gorobon", nullptr },
    { "Gotogoton", nullptr },
    { "GraphicsAreaController", nullptr },
    { "GraphicsObjShadowMaskCube", nullptr },
    { "GraphicsObjShadowMaskSphere", nullptr },
    { "GrassHigh", nullptr },
    { "GreenCoin", nullptr },
    { "GreenRing", nullptr },
    { "GreenStar", nullptr },
    { "GreenStarMisteryBoxSeries", nullptr },
    { "GreenStarKinopioBrigade", nullptr },
    { "GreenStarStand", nullptr },
    { "GroupClippingDummyTarget", nullptr },
    { "GustWind", nullptr },
    { "GuideObj", nullptr },
    { "GuideMessageAppear", nullptr },
    { "Hacchin", nullptr },
    { "HammerBros", nullptr },
    { "HexScrollAppearParts", nullptr },
    { "IllustItem", nullptr },
    { "Imozo", nullptr },
    { "InkBomb", nullptr },
    { "InkPatch", nullptr },
    { "InkPuddle", nullptr },
    { "InteractableCatToy", nullptr },
    { "IntroFlyOverCamera", nullptr },
    { "IslandFlag", nullptr },
    { "IslandKeyMoveMapParts", nullptr },
    { "ItemBubbleSingleMode", nullptr },
    { "JumpFlipPanel", nullptr },
    { "JumpFlipSweetsCream", nullptr },
    { "JumpPanel", nullptr },
    { "Kameck", nullptr },
    { "KarakuriCastleDoorWatcher", nullptr },
    { "KaronWing", nullptr },
    { "KeyMoveMapParts", nullptr },
    { "KeyMoveMapPartsGenerator", nullptr },
    { "KeyMoveLoopLiftGenerator", nullptr },
    { "KillerLauncher", nullptr },
    { "KillerTankPartsNeedle", nullptr },
    { "KinokoGiga", nullptr },
    { "KinokoOneUp", nullptr },
    { "KinokoOneUpCourseSelect", nullptr },
    { "KinokoSuper", nullptr },
    { "KinokoTreasure", nullptr },
    { "KinopioBrigadeChecker", nullptr },
    { "KinopioBrigadeNpc", nullptr },
    { "KinopioBrigadeWatcher", nullptr },
    { "KinopioNpc", nullptr },
    { "Koura", nullptr },
    { "KouraGold", nullptr },
    { "KoopaChase", nullptr },
    { "KoopaChaseWarpDummy", nullptr },
    { "KoopaChaseCar", nullptr },
    { "KoopaFireBallGenerator", nullptr },
    { "KoopaGraffiti", nullptr },
    { "KoopaLastAttackFire", nullptr },
    { "KoopaLastBeforeCheckPoint", nullptr },
    { "KoopaLastBlockPow", nullptr },
    { "KoopaLastBreakWall", nullptr },
    { "KoopaLastDefendeBlockPow", nullptr },
    { "KoopaLastDemoAppear", nullptr },
    { "KoopaLastFloor", nullptr },
    { "KoopaLastWall", nullptr },
    { "KoopaLastWallClimb", nullptr },
    { "KoopaLastWallClimbDown", nullptr },
    { "KoopaSignBoard", nullptr },
    { "Kuribo", nullptr },
    { "KuriboClimbRail", nullptr },
    { "KuriboClimbSyncObj", nullptr },
    { "KuriboMini", nullptr },
    { "KuriboMiniGenerator", nullptr },
    { "KuriboTower", nullptr },
    { "KyoroHei", nullptr },
    { "Kyuppon", nullptr },
    { "Lantern", nullptr },
    { "LavaGeyser", nullptr },
    { "LiftMike", nullptr },
    { "LiftMikeBlockRail", nullptr },
    { "LiftMikeSlide", nullptr },
    { "Lighthouse", nullptr },
    { "LighthouseSimple", nullptr },
    { "LightningController", nullptr },
    { "LuckyIsland", nullptr },
    { "LuckyIslandController", nullptr },
    { "MagmaFish", nullptr },
    { "MarchGenerator", nullptr },
    { "MeraWanwan", nullptr },
    { "Mirror", nullptr },
    { "MoamoaHolder", nullptr },
    { "MultiLift", nullptr },
    { "MysteryBox", nullptr },
    { "MysteryHouseChecker", nullptr },
    { "NeedleBarRoot", nullptr },
    { "NeedleRoller", nullptr },
    { "NeedleRollerGenerator", nullptr },
    { "NeedleRollerSwing", nullptr },
    { "NeedleSeed", nullptr },
    { "NeedleTrap", nullptr },
    { "Neko", nullptr },
    { "NekoParent", nullptr },
    { "Nokonoko", nullptr },
    { "OccludedEffectRequester", nullptr },
    { "OceanWaterIndirect", nullptr },
    { "OceanWaterDynamicV1", nullptr },
    { "OceanWaterDynamicDeferred", nullptr },
    { "OneSideStep", nullptr },
    { "OneSideStepGenerator", nullptr },
    { "PackunFire", nullptr },
    { "PackunFlower", nullptr },
    { "PackunFlowerWithPot", nullptr },
    { "PanelNotePaint", nullptr },
    { "PanelNotePaintGroup", nullptr },
    { "Peto", nullptr },
    { "PipePackun", nullptr },
    { "PlayerPointLightingObj", nullptr },
    { "PlayerSpotLightingObj", nullptr },
    { "PlessieTerrain", nullptr },
    { "PrePassLineLight", nullptr },
    { "PrePassPointLight", nullptr },
    { "PrePassProjLight", nullptr },
    { "PrePassProjOrthoLight", nullptr },
    { "PrePassSpotLight", nullptr },
    { "PressureDeathObj", nullptr },
    { "PSwitchTimerCoinWatcher", nullptr },
    { "BoxPropeller", nullptr },
    { "PlayerNpc", nullptr },
    { "Prominence", nullptr },
    { "Pukupuku", nullptr },
    { "PukupukuFly", nullptr },
    { "Punpun", nullptr },
    { "Rabbit", nullptr },
    { "RabbitNpc", nullptr },
    { "RabbitBig", nullptr },
    { "RaftConveyer", nullptr },
    { "Raidon", nullptr },
    { "RaidonNpc", nullptr },
    { "RaidonSurf", nullptr },
    { "RailMoveMapParts", nullptr },
    { "Kuribon", nullptr },
    { "RingBeamer", nullptr },
    { "RollingCubeMapParts", nullptr },
    { "RollingCubeMapPartsGenerator", nullptr },
    { "RotateMapParts", nullptr },
    { "RouteDokan", nullptr },
    { "RouteDokanBazooka", nullptr },
    { "RouteDokanLauncher", nullptr },
    { "Runner", nullptr },
    { "SaveDataChecker", nullptr },
    { "SamboSnowHead", nullptr },
    { "SePlayObj", nullptr },
    { "SePlayRail", nullptr },
    { "Seaweed", nullptr },
    { "SeesawMapParts", nullptr },
    { "Shards", nullptr },
    { "ShardsWatcher", nullptr },
    { "ShadowMarioPlayerHolder", nullptr },
    { "SignBoard", nullptr },
    { "SingleModeCheckpoint", nullptr },
    { "SingleModeCheckpointFlag", nullptr },
    { "SinkedItem", nullptr },
    { "SkateShoes", nullptr },
    { "Skatis", nullptr },
    { "Skipper", nullptr },
    { "SkipperWeak", nullptr },
    { "Sky", nullptr },
    { "SkyProjection", nullptr },
    { "SlideMapParts", nullptr },
    { "SoundKeyMoveParts", nullptr },
    { "Spinner", nullptr },
    { "SplatterPlotter", nullptr },
    { "SpotLightPatroller", nullptr },
    { "SpotLightPatrollerObserver", nullptr },
    { "StageStartBindDemoCasinoRoom", nullptr },
    { "StageStartBindDemoKinopioBrigade", nullptr },
    { "StageStartBindDemoKinopioHouse", nullptr },
    { "StageStartBindDemoMysteryHouse", nullptr },
    { "StageStartEventCamera", nullptr },
    { "StageStartEventDemo", nullptr },
    { "StageStartEventSound", nullptr },
    { "StepScrollWatcher", nullptr },
    { "StrongHipDropReactPoint", nullptr },
    { "SuperBell", nullptr },
    { "SuperBellSpecial", nullptr },
    { "GigaBell", nullptr },
    { "KuriboGiga", nullptr },
    { "GigaBellManager", nullptr },
    { "GigaBellPedestal", nullptr },
    { "GigaRock", nullptr },
    { "SuperBowser", nullptr },
    { "SuperBowserShell", nullptr },
    { "SuperbViewArea", nullptr },
    { "SuperKoura", nullptr },
    { "SuperLeaf", nullptr },
    { "SuperSkateRail", nullptr },
    { "SuperSkateShoes", nullptr },
    { "SuperStar", nullptr },
    { "SurfMapParts", nullptr },
    { "Swimmer", nullptr },
    { "SwingMapParts", nullptr },
    { "SwitchAnd", nullptr },
    { "SwitchRotateWatcher", nullptr },
    { "SwitchBlockWatcher", nullptr },
    { "SwitchBlockMapParts", nullptr },
    { "SyumockConveyerGenerator", nullptr },
    { "SyumockRailMove", nullptr },
    { "SyumockRotate", nullptr },
    { "Takobo", nullptr },
    { "Tentack", nullptr },
    { "TentackLv3", nullptr },
    { "TentenGenerator", nullptr },
    { "TentenGeneratorNormal", nullptr },
    { "Teren", nullptr },
    { "Teresa", nullptr },
    { "TeresaConveyorBench", nullptr },
    { "TeresaConveyorTeresaBig", nullptr },
    { "TeresaFakeDokan", nullptr },
    { "TeresaFakeObject", nullptr },
    { "TeresaWall", nullptr },
    { "Tico", nullptr },
    { "TicoCourseSelect", nullptr },
    { "TimerClock", nullptr },
    { "TimerCoinHolder", nullptr },
    { "TimerGate", nullptr },
    { "TimerStageSwitch", nullptr },
    { "Togezo", nullptr },
    { "TouchReactionMapParts", nullptr },
    { "TrampleSwitchTimer", nullptr },
    { "TrampleSwitch", nullptr },
    { "TrampleSwitchChara", nullptr },
    { "TrampleSwitchGoalItem", nullptr },
    { "TrampleSwitchGold", nullptr },
    { "TrampleSwitchTogetherWatcher", nullptr },
    { "Trampoline", nullptr },
    { "TransparentWall", nullptr },
    { "Trapeze", nullptr },
    { "Tree", nullptr },
    { "TreeFarLodWatcher", nullptr },
    { "TreeStump", nullptr },
    { "TreeStumpWatcher", nullptr },
    { "Tuccondor", nullptr },
    { "TuccondorAround", nullptr },
    { "TuccondorTrap", nullptr },
    { "Ukibo", nullptr },
    { "VisibleSwitchMapParts", nullptr },
    { "WarpCube", nullptr },
    { "WarpDoor", nullptr },
    { "WaterAreaMoveModel", nullptr },
    { "WheelMapParts", nullptr },
    { "WheelWatcher", nullptr },
    { "WobbleMapParts", nullptr },
    { "WoodBox", nullptr },
    { "WoodLogBridge", nullptr },
    { "ZigzagBuildingCover", nullptr },
    { "TestAndoBowserJr", nullptr },
    { "KoopaJr", nullptr },
    { "ThrowMapParts", nullptr },
    { "TimeLimitStepSwitch", nullptr },
    { "WindowMessageAppear", nullptr },
    { "ZoneHolder", nullptr },
    { "Island", nullptr },
    { "TestAndoGoalPole", nullptr }
};

ProjectActorFactory::ProjectActorFactory() : ActorFactory("アクターファクトリー") {
    mFuncs = cCreateTable;
    mNumEntries = 0x1CB;
}
