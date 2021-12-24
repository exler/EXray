#ifndef ENTITY_LIST_H
#define ENTITY_LIST_H

#include <memory>
#include <vector>

#include "Entity.hpp"
#include "Ray.hpp"

class EntityList
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

    bool check_objects_hit(const Ray &r, float t_min, float t_max, HitRecord &rec) const;

private:
    std::vector<Entity::ptr> _objects;
};

#endif
