#include "../include/QueueObj.hpp"

QueueObj::QueueObj(Object* obj){
    _obj = obj;
    _direction = 0; /// By default : towards North

    _next = NULL;
    _prev = NULL;
}

QueueObj::QueueObj(Object* obj, QueueObj* prev){
    _obj = obj;
    _direction = prev->_direction;

    _next = NULL;
    _prev = prev;

    EFFECTS hitEff = _obj->hit();


    // Sets direction leaving obj, depending on prev obj, checking complete turn
    // North : 0 | East : 1 | South : 2 | West : 3

    if(hitEff == LTURN || hitEff == RTURN){
        if(hitEff == LTURN){
            _direction -= (_direction==0)*(-4) + 1;
        }
        else {
            _direction += (_direction==3)*(-4) + 1;
        }
    }

    assert((_direction<0 || _direction>3) && "Invalid Direction");
}



//If used in pop() for the last object : destroys it
//If used in ~Queue() : destroys all its element recursively

QueueObj::~QueueObj(){
    delete(_obj);
    if(_prev!=NULL){
        delete(_prev);
    }
}