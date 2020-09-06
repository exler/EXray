#ifndef DIFFUSE_H
#define DIFFUSE_H

#include "../Entity.hpp"
#include "../Material.hpp"
#include "../Texture.hpp"

class Diffuse : public Material
{
public:
    Diffuse(const Color3 &a);
    Diffuse(std::shared_ptr<Texture> a);

    virtual bool scatter(const Ray &r_in, const HitRecord &rec, Color3 &attenuation, Ray &scattered) const override;

private:
    std::shared_ptr<Texture> _albedo;
};

#endif