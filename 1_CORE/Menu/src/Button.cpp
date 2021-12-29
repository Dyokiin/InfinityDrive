#include "../include/Button.hpp"

bool Button::isHovered(const int &x, const int &y) const {
    bool returnStmt = false;
    if((x <= _corner2.x && x >= _corner1.x) && ( y <= _corner2.y && y >= _corner1.y)){
        returnStmt = true;
    }
    return returnStmt;
}

int Button::click(const int &x, const int &y) const {
    int returnStmt = -1;
    if(this->isHovered(x,y)){
        returnStmt = _signal;
    }
    return returnStmt;
}