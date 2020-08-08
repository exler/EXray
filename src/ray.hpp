#ifndef RAY_H
#define RAY_H

#include "vector3.hpp"

class Ray
{
public:
    Ray();
    Ray(const Vector3 &origin, const Vector3 &direction);

    Vector3 origin() const;
    Vector3 direction() const;

    Vector3 at(double t) const;

    Vector3 lerp(const Vector3 &start_color, const Vector3 &end_color) const;

private:
    Vector3 _orig;
    Vector3 _dir;
};

#endif