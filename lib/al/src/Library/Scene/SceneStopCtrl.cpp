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

    // https://decomp.me/scratch/7wXTT
    void SceneStopCtrl::update() {
        int val = _4;

        if (val-- < 0) {
            int otherVal = _0;

            if (otherVal-- < 0) {
                _8 = false;
                _9 = false;
            }
            else {
                _0 = otherVal;
            }
        }
        else {
            _4 = val;
        }
    }
};