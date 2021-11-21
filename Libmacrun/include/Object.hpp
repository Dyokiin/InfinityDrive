#pragma once

#include <vector>
#include "HitBox.hpp"
#include <GL/glew.h>
#include <GL/gl.h>
#include <glm/glm.hpp>
#include <iostream>

#include "HitBox.hpp"

typedef struct ShapeVertexTex {
    glm::vec3 _position;
    glm::vec3 _normal;
    glm::vec2 _texCoords;
} VertexPNT;


class Object {

protected :

    //Shape _vertice;*
    std::vector<ShapeVertexTex> _vertice;
    HitBox _hitBox;
    int _objId;

public :

    Object() = default;
    Object(const std::vector<ShapeVertexTex> vertices, const HitBox hb, const int id) 
    : _vertice(vertices), _hitBox(hb), _objId(id) {};

    ~Object() = default;


    inline bool collide(const Object obj) const {return _hitBox.intersect(obj._hitBox);};
    inline EFFECTS hit() const {return _hitBox.effect();};

    inline GLsizei getNbVertex() const {return _vertice.size();}
    inline const ShapeVertexTex* getDataPointer() const {return &_vertice[0];}
    inline std::vector<ShapeVertexTex> getVertice() const {return _vertice;};

    inline int getId() const {return _objId;};


};

class PermanentObject : public Object {
private:
    glm::vec3 _speed;
    double _distGarbageColl;

public:
    PermanentObject();
    ~PermanentObject();


};