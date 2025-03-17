#include "Library/Scene/SceneStopCtrl.hpp"

namespace al {
    SceneStopCtrl::SceneStopCtrl() { 

    }

    void SceneStopCtrl::reqeustStopScene(int a1, int a2, bool a3, bool a4) {
        if (_0 <= 0 && _4 <= 0) {
            _4 = a2;

            if (_0 >= a1) {
                _8 = a3;
                _9 = a4;
                return;
            }
        }

        if (_0 < a1) {
            _0 = a1;
        }

        _8 = a3;
        _9 = a4;
    }

    void SceneStopCtrl::update() {
        if (_4 >= 1)
            _4--;
        else if (_0 >= 1) {
            _0--;
        } else {
            _8 = false;
            _9 = false;
        }
    }
};