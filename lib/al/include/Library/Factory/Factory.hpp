#pragma once

#include <basis/seadTypes.h>

namespace al {
    class MemorySceneHeapCustomAlloc;

    template <typename T>
    struct NameToCreator {
        const char* name;
        T func;
    };
    
    template<typename T>
    class Factory {
    public:
        inline Factory(const char *pName) : mName(pName), mFuncs(nullptr), mNumEntries(0) {
            
        }

        virtual const char* convertName(const char *) const;

        const char* mName;                          // 0x08
        const NameToCreator<T>* mFuncs;             // 0x10
        s32 mNumEntries;                            // 0x18
    };
};