#ifndef ENTITY_LIST_H
#define ENTITY_LIST_H

#include <memory>
#include <vector>

#include "Entity.hpp"
#include "Ray.hpp"
#include "AABB.hpp"

class EntityList : public Entity
{
public:
    EntityList();
    EntityList(Entity::ptr object);

    void clear();
    void add(Entity::ptr object);

    std::vector<Entity::ptr> obj()
    {
        return _objects;
    }

    virtual bool hit(const Ray &r, float t_min, float t_max, HitRecord &rec) const override;
    virtual bool bounding_box(float t0, float t1, AABB &output_box) const override;

private:
    std::vector<Entity::ptr> _objects;
};

#endif