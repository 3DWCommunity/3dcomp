#include "Library/Scene/SceneFunction.hpp"

namespace alSceneFunction {
    SceneFactory::SceneFactory(const char *pName) : al::Factory<SceneFunction>(pName) {

    };

    al::MemorySceneHeapCustomAlloc* SceneFactory::tryGetCustomAlloc(const char *) {
        return nullptr;
    }
};