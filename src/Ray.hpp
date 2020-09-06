#ifndef RAY_H
#define RAY_H

#include "Utility.hpp"
#include "Vector3.hpp"

class Ray
{
public:
    Ray();
    Ray(const Vector3 &origin, const Vector3 &direction, float time = 0.0);

    Vector3 origin() const;
    Vector3 direction() const;
    float time() const;

    Vector3 at(float t) const;

private:
    Vector3 _orig;
    Vector3 _dir;
    float _time;
};

#endif