#ifndef LIGHT_H
#define LIGHT_H

#include <memory>

#include "../Vector3.hpp"
#include "../Material.hpp"
#include "../Texture.hpp"
#include "../textures/SolidColor.hpp"

class Light : public Material
{
public:
    Light(std::shared_ptr<Texture> a);
    Light(Color3 c);

    virtual bool scatter(const Ray &r_in, const HitRecord &rec, Color3 &attenuation, Ray &scattered) const override;
    virtual Color3 emitted(float u, float v) const;

private:
    std::shared_ptr<Texture> _emit;
};

#endif
