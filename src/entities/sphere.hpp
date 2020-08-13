#ifndef SPHERE_H
#define SPHERE_H

#include <cmath>

#include "../entity.hpp"
#include "../vector3.hpp"
#include "../ray.hpp"

class Sphere : public Entity
{
public:
    Sphere();
    Sphere(Vector3 c, float r);

    virtual bool hit(const Ray &r, double t_min, double t_max, HitRecord &rec) const override;

private:
    Vector3 _center;
    float _radius;
};

#endif