#ifndef SPHERE_H
#define SPHERE_H

#include <cmath>

#include "../Entity.hpp"
#include "../Vector3.hpp"
#include "../Ray.hpp"
#include "../AABB.hpp"
#include "../Utility.hpp"

class Sphere : public Entity
{
public:
    Sphere();
    Sphere(Vector3 c, float r, std::shared_ptr<Material> m);

    virtual bool hit(const Ray &r, float t_min, float t_max, HitRecord &rec) const override;
    virtual bool bounding_box(float t0, float t1, AABB &output_box) const override;

    static void get_sphere_uv(const Vector3 &p, float &u, float &v);

private:
    Vector3 _center;
    float _radius;
    std::shared_ptr<Material> _material;
};

#endif