#ifndef BOX_H
#define BOX_H

#include <memory>

#include "../Vector3.hpp"
#include "../Ray.hpp"
#include "../Entity.hpp"
#include "../EntityList.hpp"
#include "../Material.hpp"

class XYRect : public Entity
{
public:
    XYRect();
    XYRect(float x0, float x1, float y0, float y1, float k,
           std::shared_ptr<Material> mat);

    virtual bool hit(const Ray &r, float t_min, float t_max, HitRecord &rec) const override;

private:
    std::shared_ptr<Material> _material;
    float _x0, _x1, _y0, _y1, _k;
};

class XZRect : public Entity
{
public:
    XZRect();
    XZRect(float x0, float x1, float z0, float z1, float k,
           std::shared_ptr<Material> mat);

    virtual bool hit(const Ray &r, float t_min, float t_max, HitRecord &rec) const override;

private:
    std::shared_ptr<Material> _material;
    float _x0, _x1, _z0, _z1, _k;
};

class YZRect : public Entity
{
public:
    YZRect();
    YZRect(float y0, float y1, float z0, float z1, float k,
           std::shared_ptr<Material> mat);

    virtual bool hit(const Ray &r, float t_min, float t_max, HitRecord &rec) const override;

private:
    std::shared_ptr<Material> _material;
    float _y0, _y1, _z0, _z1, _k;
};

class Box : public Entity
{
public:
    Box();
    Box(const Vector3 &p0, const Vector3 &p1, std::shared_ptr<Material> ptr);

    virtual bool hit(const Ray &r, float t_min, float t_max, HitRecord &rec) const override;

private:
    Vector3 _box_min, _box_max;
    EntityList _sides;
};

#endif
