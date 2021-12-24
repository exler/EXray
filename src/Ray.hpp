#ifndef RAY_H
#define RAY_H

#include "Utility.hpp"
#include "Vector3.hpp"

class Ray
{
public:
    Ray() {}
    Ray(const Vector3 &origin, const Vector3 &direction, float time)
        : _orig(origin), _dir(direction), _time(time) {}

    Vector3 origin() const
    {
        return _orig;
    }
    Vector3 direction() const
    {
        return _dir;
    }
    float time() const
    {
        return _time;
    }

    Vector3 at(float t) const
    {
        return _orig + t * _dir;
    }

private:
    Vector3 _orig;
    Vector3 _dir;
    float _time;
};

#endif
