#ifndef MATERIAL_H
#define MATERIAL_H

#include "Ray.hpp"
#include "Vector3.hpp"

struct HitRecord;

class Material
{
public:
    virtual bool scatter(const Ray &r_in, const HitRecord &rec, Color3 &attenuation, Ray &scattered) const = 0;
};

#endif