#pragma once 

class Camera {
private:
    double _distance;
    double _angleX;
    double _angleY;
    double _angleZ;

public:

    Camera();
    ~Camera() = default;

    void moveFront(const float delta);
    void rotateLeft(const float alpha);
    void rotateUp(const float gamma);

}