#ifndef ENTITY_H
#define ENTITY_H

#include "ray.hpp"

struct HitRecord
{
    Vector3 p;
    Vector3 normal;
    float t;
};

class Entity
{
public:
    virtual bool hit(const Ray &r, double t_min, double t_max, HitRecord &rec) const = 0;
};

#endif