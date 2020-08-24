#ifndef ENTITY_LIST_H
#define ENTITY_LIST_H

#include <memory>
#include <vector>

#include "Entity.hpp"
#include "Ray.hpp"

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

    virtual bool hit(const Ray &r, double t_min, double t_max, HitRecord &rec) const override;

private:
    std::vector<std::shared_ptr<Entity>> _objects;
};

#endif