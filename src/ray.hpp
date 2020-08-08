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

private:
    Vector3 orig;
    Vector3 dir;
};

#endif