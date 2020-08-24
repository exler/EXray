#ifndef DIFFUSE_H
#define DIFFUSE_H

#include "../Entity.hpp"
#include "../Material.hpp"

class Diffuse : public Material
{
public:
    Diffuse(const Color3 &a);

    virtual bool scatter(const Ray &r_in, const HitRecord &rec, Color3 &attenuation, Ray &scattered) const override;

private:
    Color3 _albedo;
};

#endif