#ifndef ENTITY_H
#define ENTITY_H

#include <memory>
#include <vector>

#include "ray.hpp"

struct HitRecord
{
    Vector3 p;
    Vector3 normal;
    float t;
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
    virtual bool hit(const Ray &r, double t_min, double t_max, HitRecord &rec) const = 0;
};

class EntityList : public Entity
{
public:
    EntityList();
    EntityList(std::shared_ptr<Entity> object);

    void clear();
    void add(std::shared_ptr<Entity> object);

    virtual bool hit(const Ray &r, double t_min, double t_max, HitRecord &rec) const override;

private:
    std::vector<std::shared_ptr<Entity>> _objects;
};

#endif