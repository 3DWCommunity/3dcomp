#pragma once

namespace al {
    class ComboCounter {
    public:
        inline ComboCounter() {
            // empty
        }

        virtual ~ComboCounter() {
            // empty
        }

        virtual void increment() {
            mCounter++;
        }

        int mCounter = 0;
    };
};  // namespace al