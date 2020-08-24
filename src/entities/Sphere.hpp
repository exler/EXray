#ifndef SPHERE_H
#define SPHERE_H

#include <cmath>

#include "../Entity.hpp"
#include "../Vector3.hpp"
#include "../Ray.hpp"

class Sphere : public Entity
{
public:
    Sphere();
    Sphere(Vector3 c, float r, std::shared_ptr<Material> m);

    virtual bool hit(const Ray &r, double t_min, double t_max, HitRecord &rec) const override;

private:
    Vector3 _center;
    float _radius;
    std::shared_ptr<Material> _material;
};

#endif