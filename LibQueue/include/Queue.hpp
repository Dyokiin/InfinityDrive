#pragma once 

#include "QueueObj.hpp"

#define MAX_ELEMENTS_IN_QUEUE 10

class Queue {
private:
    QueueObj* _first;
    QueueObj* _last;
    int total;

public :

    Queue() = default;
    Queue(QueueObj* first) 
    : _first(first), _last(first), total(1) {};

    ~Queue();

    void add(QueueObj* obj);
    void pop();


    // TODO : Rendering : Meshify ? .render() ? 

};