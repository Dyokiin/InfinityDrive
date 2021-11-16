#include "../include/Object.hpp"

EFFECTS Object::hit(const Object obj) const {
    EFFECTS rtrnEff = NONE;
    if(_hitBox.intersect(obj._hitBox)){
        rtrnEff = obj._hitBox.effect();
    }
    return rtrnEff;
}