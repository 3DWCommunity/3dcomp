#pragma once

#include "Library/Factory/Factory.hpp"

namespace al {
    class Scene;
};

namespace alSceneFunction {
    typedef al::Scene* (*SceneFunction)(void);
    class SceneFactory : public al::Factory<SceneFunction> {
    public:
        SceneFactory(const char *);

        virtual al::MemorySceneHeapCustomAlloc* tryGetCustomAlloc(const char *);
    };
};