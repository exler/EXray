#ifndef METAL_H
#define METAL_H

#include "../Entity.hpp"
#include "../Material.hpp"

class Metal : public Material
{
public:
    Metal(const Color3 &a, float f);

    virtual bool scatter(const Ray &r_in, const HitRecord &rec, Color3 &attenuation, Ray &scattered) const override;

private:
    Color3 _albedo;
    float _fuzz;
};

#endif