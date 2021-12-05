#include "../../../2_VISU/Mesh/include/Model.hpp"
#include "../../Box/include/HitBox.hpp"
#include <glm/gtx/transform.hpp>



class Object{
protected:
    Model _model;
    HitBox _hitBox;

public:
    Object();
    Object(Model model,  HitBox hitbox)
    : _model(model), _hitBox(hitbox) {}
    ~Object() = default;

    void Draw(MyShader shader, const glm::mat4 MVmatrix, const glm::mat4 MVPmatrix) const;
};

class Road : public Object {
private:
    Box _boundingBox;
    glm::mat4 _endPath;
    std::vector<Object> _coins;

public:
    Road() : Object() {}
    Road(Model model, HitBox hitbox, Box bndbox, glm::mat4 endpth, std::vector<Object> coins)
    : Object(model, hitbox), _boundingBox(bndbox), _endPath(endpth), _coins(coins) {}
    ~Road() = default;

    void Draw(MyShader shader, const glm::mat4 MVmatrix, const glm::mat4 MVPmatrix) const;
};

class Car : public Object {
public :
    float _speed;

private :
    Car() : Object() {}
    Car(Model model, HitBox hitbox) 
    : Object(model, hitbox), _speed(0.f) {}

    void Draw(MyShader shader, const glm::mat4 MVmatrix, const glm::mat4 MVPmatrix) const;
    
};