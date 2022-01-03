#pragma once

#include "Model.hpp"
#include "../../../1_CORE/Box/include/HitBox.hpp"

#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/transform.hpp>
#include <glm/gtx/norm.hpp>


#define CAR_MAX_SPEED 0.8
#define CARS_MAX_DIST 2

/// \enum DIRECTION
/// \brief Normalized direction signals
enum DIRECTION {JUMP, LEFT, RIGHT, KEEP};

/// \class Object
/// \brief Basic object of the game
class Object{
//protected to be used by legacy 
protected:
    Model _model;   /*!< Model of the Object */
    HitBox _hitBox; /*!< HitBox of the object */

public:
    /// \brief default constructor
    Object();
    /// \brief Constructor
    /// \param model : Model of the Object
    /// \param hitbox : hitbox of the object
    Object(Model model,  HitBox hitbox)
    : _model(model), _hitBox(hitbox) {}
    /// \brief default Destructor
    ~Object() = default;

    /// \brief Draw the object
    /// \param Shader : Shader to pass material of Model
    void Draw(MyShader &Shader) const;
    /// \brief Getter for Hitbox
    inline const HitBox getHitBox() const {return _hitBox;}
};

/// \class Road
/// \brief Implements roads element : legacy of Object
class Road : public Object {
private:
    Box _boundingBox;   /*!< Bounding Box of the Road */
    glm::mat4 _endPath; /*!< 4x4 Matrix helping to place the next element */

    std::vector<Object> _coins; /*!< Vector of the coins present on this road */
    bool _realCoins;    /*!< Are the coins displayed */

public:
    /// \brief Constructor : Parent constructor
    Road() : Object() {}
    /// \brief Constructor
    /// \param model : Model
    /// \param hitbox : HitBox
    /// \param bndbox : Bounding box
    /// \param endpth : 4x4 matrix endPath
    Road(Model model, HitBox hitbox, Box bndbox, glm::mat4 endpth)
    : Object(model, hitbox), _boundingBox(bndbox), _endPath(endpth) {}
    /// \brief Default destructor
    ~Road() = default;

    /// \brief Getter for realCoins
    inline const bool isCoins() const {return _realCoins;}
    /// \brief Gette for the Bounding Box
    inline Box getBnBox() const {return _boundingBox;}
    /// \brief setter for realcoins
    /// \param yN : bool to set realcoins to
    inline void setCoins(bool yN) {_realCoins = yN;}
    /// \brief getter for endPath
    inline glm::mat4 getEndPth() const {return _endPath;}
    /// \brief Draw the road
    /// \param Shader : To pass material
    void Draw(MyShader &Shader) const;
};

/// \class Car
/// \brief Main Car class, legacy of object
class Car : public Object {
private :
    glm::vec3 _pos;         /*!< Position vector of the car */
    glm::vec3 _Cspeed;      /*!< Cartesian speed vector of the car */
    glm::vec3 _Caccel;      /*!< Cartesian acceleration vector of the car */
    glm::vec3 _aSpeed;      /*!< Rotational speed */
    glm::vec3 _aAccel;      /*!< Rotationnal acceleration */
    glm::mat4 _modelMatrix; /*!< Model Matrix  */
    glm::mat4 _rotMatrix;   /*!< Rotation Matrix : stock all rotations independently from the Model Matrix */
    bool _targetable;       /*!< is the car able to hit something */

public :
    /// \brief Default constructor : Parent constructor
    Car() : Object() {}
    /// \brief Constructor
    /// \param model : Model
    /// \param hitbox : Hitbox
    Car(Model model, HitBox hitbox) 
    : Object(model, hitbox), _pos(0.f), _Cspeed(0,0,0.2), _Caccel(0.,-0.008,0.00001),
    _aSpeed(0.f), _aAccel(-0.01), _modelMatrix(1.f), _rotMatrix(1.f), _targetable(true) {
        _modelMatrix *= glm::translate(glm::vec3(0,1,96));
        _hitBox.translate(glm::translate(glm::vec3(0,1,97)));
    }
    /// \brief default destructor
    ~Car();

    /// \brief Update Car postion, ... depending on its current state 
    void update(); 
    /// \brief update car behaviour from an effect
    /// \param e : effect to take into account 
    void update(EFFECTS e);
    /// \brief update car behaviour from a direction
    /// \param d : direction to take into account
    void update(DIRECTION d);
    /// \brief getter for Model Matrix
    inline const glm::mat4 getModelMat() const {return _modelMatrix;}
    /// \brief getter for Rotation Matrix
    inline const glm::mat4 getRotModelMat() const {return _modelMatrix * _rotMatrix;}
    /// \brief getter for targetable
    inline const bool isTargetable() const {return _targetable;}
    /// \brief setter for targetable
    /// \param yN : targetable to set to 
    inline void toggleTarget(bool yN) {_targetable = yN;}
    /// \brief Draw the car
    /// \param Shader : Materials
    void Draw(MyShader &Shader) const;
};

std::vector<Road> loadObject();