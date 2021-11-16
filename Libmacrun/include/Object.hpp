#pragma once

#include "HitBox.hpp"
#include "Shapes.hpp"

class Object {

private :
    Shape _mesh;
    HitBox _hitBox;

public :
    Object() = default;
    Object(const std::vector<ShapeVertexTex> vertices, const HitBox hb) 
    : _mesh(vertices), _hitBox(hb) {};

    ~Object() = default;

    EFFECTS hit(const Object obj) const;

    inline void render() const {_mesh.render();};
};
