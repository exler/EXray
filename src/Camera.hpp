#ifndef CAMERA_H
#define CAMERA_H

#include <cmath>

#include "Vector3.hpp"
#include "Ray.hpp"
#include "Utility.hpp"

class Camera
{
public:
    Camera(float aspect_ratio,
           float vertical_fov,
           Vector3 lookfrom,
           Vector3 lookat,
           Vector3 vup,
           float aperture,
           float focus_dist);

    Ray get_ray(float u, float v) const;

private:
    Vector3 _origin;
    Vector3 _horizontal;
    Vector3 _vertical;
    Vector3 _lower_left_corner;
    Vector3 _u, _v;
    float _lens_radius;
};

#endif