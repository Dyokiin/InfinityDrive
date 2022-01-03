#pragma once 

#include "Box.hpp"

#include <functional>

/// \enum EFFECTS
/// \brief Enum of Hitbox effects
enum EFFECTS {FALL, SLOW, CAUTGH, BURST, LTURN, RTURN, NONE};

/// \class Hitbox
/// \brief Class dfining an Hitbox for collisions with effects
class HitBox {

private:

    Box _border;    /*!< Box of the hitbox */
    EFFECTS _hit;   /*!< Effect of the Hitbox */

public:

    /// \brief Default constructor
    HitBox()
    : _border(0,0,0,0,0,0), _hit(BURST) {}

    /// \brief Constructor from a Box and an effect
    /// \param border : Box of the Hitbox
    /// \param E : effect of the Hitbox, BURST by default
    HitBox(const Box border, const EFFECTS E = BURST)
    : _border(border), _hit(E) {}

    /// \brief Default destructor
    ~HitBox() = default;

    /// \brief Effect setter
    /// \param hit : effect to set to
    void setEffect(const EFFECTS hit);

    /// \brief Fonction used to translate an Hitbox
    /// \param transMat : 4x4 Translation Matrix
    inline void translate(glm::mat4 transMat) {_border.translate(transMat);}

    /// \brief Check if two boxes intersects
    /// \param hb : the other hitbox to check
    inline bool intersect(const HitBox hb) const {return _border.intersect(hb._border);}
    /// \brief Check if two boxes intersects
    /// \param hb : the other hitbox to check
    inline bool pIntersect(const HitBox hb) const {return _border.pIntersect(hb._border);}
    /// \brief Check if an Hitbox interstects a Box
    /// \param box : Box to check
    inline bool intersect(const Box box) const {return _border.intersect(box);}

    /// \brief getter for effect element
    inline EFFECTS effect() const {return _hit;}
};