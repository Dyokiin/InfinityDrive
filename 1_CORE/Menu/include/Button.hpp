#pragma once

#include "../include/TtfManager.hpp"
#include "../../../2_VISU/Scene/include/mesh.hpp"

class Label {
protected:
    Mesh _label;

public:
    Label() = default;
    ~Label() = default;
    Label(const Mesh &mesh)
    : _label(mesh) {}

    inline void display() const {_label.Draw();}
    inline int click(const int &x, const int &y) const {return -1;}
};


class Button : public Label{
private:
    glm::vec2 _corner1;
    glm::vec2 _corner2;
    int _signal;

public:

    Button() = default;
    ~Button() = default;
    Button(glm::vec2 corner1, glm::vec2 corner2, Mesh &mesh, int signal)
    : Label(mesh), _corner1(corner1), _corner2(corner2), _signal(signal) {}

    bool isHovered(const int &x, const int &y) const;
    int  click(const int &x, const int &y) const;
    inline void display() const {Label::display();}
};

