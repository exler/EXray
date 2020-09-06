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
    EntityList(std::shared_ptr<Entity> object);

    void clear();
    void add(std::shared_ptr<Entity> object);

    std::vector<std::shared_ptr<Entity>> obj()
    {
        return _objects;
    }

    virtual bool hit(const Ray &r, float t_min, float t_max, HitRecord &rec) const override;
    virtual bool bounding_box(float t0, float t1, AABB &output_box) const override;

private:
    std::vector<std::shared_ptr<Entity>> _objects;
};

#endif