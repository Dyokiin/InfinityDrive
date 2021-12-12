#pragma once 

#include "Box.hpp"

#include <functional>

enum EFFECTS {FALL, SLOW, CAUTGH, BURST, LTURN, RTURN, NONE};

class HitBox {

private:

    Box _border;
    EFFECTS _hit;

public:

    //Default constructor
    HitBox()
    : _border(0,0,0,0,0,0), _hit(BURST) {}

    HitBox(const Box border, const EFFECTS E = BURST)
    : _border(border), _hit(E) {}

    //Default destructor
    ~HitBox() = default;


    void setEffect(const EFFECTS hit);

    void render() const;

    inline void translate(glm::mat4 transMat) {_border.translate(transMat);}
    inline bool intersect(const HitBox hb) const {return _border.intersect(hb._border);}
    inline bool intersect(const Box box) const {return _border.intersect(box);}
    inline std::string toString() const {return _border.toString();}
    inline EFFECTS effect() const {return _hit;}
};