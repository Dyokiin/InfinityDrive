#include "../../../2_VISU/Mesh/include/Model.hpp"
#include "../../Box/include/HitBox.hpp"

#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/transform.hpp>


#define CAR_MAX_SPEED 10
#define CARS_MAX_DIST 2



class Object{
protected:
    Model _model;
    HitBox _hitBox;

public:
    Object();
    Object(Model model,  HitBox hitbox)
    : _model(model), _hitBox(hitbox) {}
    ~Object() = default;

    void Draw() const;
};

class Road : public Object {
private:
    Box _boundingBox;
    glm::mat4 _endPath;

    std::vector<Object> _coins;
    bool _realCoins;

public:
    Road() : Object() {}
    Road(Model model, HitBox hitbox, Box bndbox, glm::mat4 endpth, std::vector<Object> coins)
    : Object(model, hitbox), _boundingBox(bndbox), _endPath(endpth) {}
    ~Road() = default;

    inline const bool isCoins() const {return _realCoins;}
    inline Box getBnBox() const {return _boundingBox;}
    inline void setCoins(bool yN) {_realCoins = yN;}
    inline glm::mat4 getEndPth() const {return _endPath;}
    void Draw() const;
};

class Car : public Object {
private :
    float _speed;
    glm::mat4 _modelMatrix;

public :
    Car() : Object() {}
    Car(Model model, HitBox hitbox) 
    : Object(model, hitbox), _speed(0.f), _modelMatrix(1.f) {}


    void update();
    void update(EFFECTS e);
    void Draw() const;
    
};

std::vector<Road> loadObject();