#pragma once

#include <basis/seadTypes.h>

namespace al {
    class SceneStopCtrl {
    public:
        SceneStopCtrl();

        void reqeustStopScene(int, int, bool, bool);
        void update();

        int _0 = -1;
        int _4 = 0;
        bool _8 = false;
        bool _9 = false;
    };
};