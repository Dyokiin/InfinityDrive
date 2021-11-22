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
    glm::mat4 _forNextObj;

public :

    Object() = default;
    Object(const std::vector<ShapeVertexTex> vertices, const HitBox hb, const int id, glm::mat4 fno) 
    : _vertice(vertices), _hitBox(hb), _objId(id), _forNextObj(fno) {};

    ~Object() = default;


    inline bool collide(const Object obj) const {return _hitBox.intersect(obj._hitBox);};
    inline EFFECTS hit() const {return _hitBox.effect();}

    inline GLsizei getNbVertex() const {return _vertice.size();}
    inline const ShapeVertexTex* getDataPointer() const {return &_vertice[0];}
    inline std::vector<ShapeVertexTex> getVertice() const {return _vertice;}
    inline glm::mat4 getMatFNO() const {return _forNextObj;}

    inline int getId() const {return _objId;}


};

class PermanentObject : public Object {
private:
    glm::vec3 _speed;
    double _distGarbageColl;

public:
    PermanentObject();
    PermanentObject(const std::vector<ShapeVertexTex> vertices, const HitBox hb, const int id, glm::mat4 fno)
    : Object(vertices, hb, id, fno), _speed(0,0,0), _distGarbageColl(0) {};
    ~PermanentObject();
    
    inline void spdUpdate(const glm::vec3 accel) {_speed *= accel;}
    inline void distUptade(const double ddist) {if(_distGarbageColl<3){_distGarbageColl+=ddist;}}
    inline bool distUpdate(EFFECTS slow) {_distGarbageColl-=1; return(_distGarbageColl<=0);}
};