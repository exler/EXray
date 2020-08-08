#include "ray.hpp"

Ray::Ray() {}
Ray::Ray(const Vector3 &origin, const Vector3 &direction)
    : orig(origin), dir(direction) {}

Vector3 Ray::origin() const
{
    return orig;
}
Vector3 Ray::direction() const
{
    return dir;
}

Vector3 Ray::at(double t) const
{
    return orig + t * dir;
}