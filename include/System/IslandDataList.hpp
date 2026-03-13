#pragma once

#include "System/GameDataHolderAccessor.hpp"

class SingleModeDataFunction {
public:
    static bool isScenarioComplete(GameDataHolderAccessor, int, int);
};