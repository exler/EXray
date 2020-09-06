#ifndef AABB_H
#define AABB_H

#include <cmath>
#include <algorithm>

#include "Vector3.hpp"
#include "Ray.hpp"

class AABB
{
public:
    AABB();
    AABB(const Vector3 &a, const Vector3 &b);

    Vector3 min() const;
    Vector3 max() const;

    bool hit(const Ray &r, float tmin, float tmax) const;

    static AABB surrounding_box(AABB box0, AABB box1);

private:
    Vector3 _min, _max;
};

#endif