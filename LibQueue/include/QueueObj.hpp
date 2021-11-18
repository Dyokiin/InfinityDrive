#pragma once

#include "Object.hpp"

class QueueObj {
private :

    Object* _obj;
    QueueObj* _next;
    QueueObj* _prev;
    int _direction; // North : 0 | East : 1 | South : 2 | West : 3


public :

    QueueObj();
    QueueObj(Object* obj);
    QueueObj(Object* obj, QueueObj* prev);

    ~QueueObj();


    // All Getters and Setters are needed here

    inline int  getDirection() const {return _direction;};
    inline QueueObj* getNext() const {return _next;};
    inline QueueObj* getPrev() const {return _prev;};

    inline void setDirerction(int dir) {_direction= dir;};
    inline void setNext(QueueObj* obj) {_next= obj;};
    inline void setPrev(QueueObj* obj) {_prev= obj;};

};