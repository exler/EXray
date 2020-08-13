#include "ray.hpp"

Ray::Ray() {}
Ray::Ray(const Vector3 &origin, const Vector3 &direction)
    : _orig(origin), _dir(direction) {}

Vector3 Ray::origin() const
{
    return _orig;
}
Vector3 Ray::direction() const
{
    return _dir;
}

Vector3 Ray::at(double t) const
{
    return _orig + t * _dir;
}