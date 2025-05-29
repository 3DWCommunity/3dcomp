#pragma once

#include "Library/Factory/Factory.hpp"
#include "Library/Yaml/ByamlIter.hpp"

namespace al {
    class LiveActor;
    
    typedef al::LiveActor* (*CreationFuncPtr)(const char *);
    
    template <typename T>
    LiveActor* createActorFunction(const char *pName) {
        return new T(pName);
    }

    class ActorFactory : public Factory<CreationFuncPtr> {
    public:
        ActorFactory(const char *);

        virtual const char* convertName(const char *) const;

        void setConvertNameData(const u8 *);
        void setConvertNameData(const ByamlIter &);

        ByamlIter mIter;            // 0x20
    };
};