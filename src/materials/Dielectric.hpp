#ifndef DIELECTRIC_H
#define DIELECTRIC_H

#include "../Entity.hpp"
#include "../Material.hpp"
#include "../Utility.hpp"

class Dielectric : public Material
{
public:
    Dielectric(float ri);

    virtual bool scatter(const Ray &r_in, const HitRecord &rec, Color3 &attenuation, Ray &scattered) const override;

private:
    float ref_idx;
};

#endif