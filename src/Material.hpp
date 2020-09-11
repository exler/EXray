#ifndef MATERIAL_H
#define MATERIAL_H

#include "Ray.hpp"
#include "Vector3.hpp"

struct HitRecord;

class Material
{
public:
    virtual bool scatter(const Ray &r_in, const HitRecord &rec, Color3 &attenuation, Ray &scattered) const = 0;
    virtual Color3 emitted(float u, float v, const Vector3 &p) const
    {
        return Color3(0, 0, 0);
    }

    static float schlick(float cos, float ref_idx)
    {
        // Returns the approximation of the reflection factor
        // https://en.wikipedia.org/wiki/Schlick%27s_approximation
        auto r0 = (1 - ref_idx) / (1 + ref_idx);
        r0 = r0 * r0;
        return r0 + (1 - r0) * pow((1 - cos), 5);
    }
};

#endif