#ifndef CAMERA_H
#define CAMERA_H

#include "vector3.hpp"
#include "ray.hpp"

class Camera
{
public:
    Camera(float aspect_ratio);

    Ray get_ray(double u, double v) const;

private:
    Vector3 _origin;
    Vector3 _horizontal;
    Vector3 _vertical;
    Vector3 _lower_left_corner;
};

#endif