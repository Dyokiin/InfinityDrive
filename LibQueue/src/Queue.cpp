#include "../include/Queue.hpp"

 Queue::~Queue(){
     delete(_last);
 }

 void Queue::add(QueueObj* obj){
     obj->setPrev(_last);
     _last->setNext(obj);
     _last = obj;

     if(total > MAX_ELEMENTS_IN_QUEUE){
         this->pop();
     }
 }

 void Queue::pop(){
     _first = _first->getNext();
     delete _first->getPrev();
     _first->setPrev(NULL);
 }