#ifndef ENTITY_H
#define ENTITY_H

#include <memory>

#include "Ray.hpp"
#include "AABB.hpp"

class Material;

struct HitRecord
{
    Vector3 p;
    Vector3 normal;
    std::shared_ptr<Material> mat;
    float t;
    float u;
    float v;
    bool front_face;

    inline void set_face_normal(const Ray &r, const Vector3 &outward_normal)
    {
        front_face = dot(r.direction(), outward_normal) < 0;
        normal = front_face ? outward_normal : -outward_normal;
    }
};

class Entity
{
public:
    virtual bool hit(const Ray &r, float t_min, float t_max, HitRecord &rec) const = 0;
    virtual bool bounding_box(float t0, float t1, AABB &output_box) const = 0;
};

#endif