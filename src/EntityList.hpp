#ifndef ENTITY_LIST_H
#define ENTITY_LIST_H

#include <memory>
#include <vector>

#include "Entity.hpp"
#include "Ray.hpp"

class EntityList : public Entity
{
public:
    EntityList() {}

    std::vector<Entity::ptr> objects;

    void clear()
    {
        objects.clear();
    }
    void add(Entity::ptr object)
    {
        objects.push_back(object);
    }

    virtual bool hit(const Ray &r, float t_min, float t_max, HitRecord &rec) const override
    {
        HitRecord temp_rec;
        bool hit = false;
        auto closest = t_max;

        for (const auto &object : objects)
        {
            if (object->hit(r, t_min, closest, temp_rec))
            {
                hit = true;
                closest = temp_rec.t;
                rec = temp_rec;
            }
        }

        return hit;
    }
};

#endif
