#pragma once

#include "HitBox.hpp"
#include "Shapes.hpp"

class Object {

private :

    Shape _mesh;
    HitBox _hitBox;
    int _objId;


public :

    Object() = default;
    Object(const std::vector<ShapeVertexTex> vertices, const HitBox hb, const int id) 
    : _mesh(vertices), _hitBox(hb), _objId(id) {};

    ~Object() = default;


    inline bool collide(const Object obj) const {return _hitBox.intersect(obj._hitBox);};

    inline EFFECTS hit() const {return _hitBox.effect();};


    inline void render() const {_mesh.render();};

    inline int getId() const {return _objId;};
};
