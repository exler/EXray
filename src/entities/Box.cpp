#include "Box.hpp"

XYRect::XYRect() {}
XYRect::XYRect(float x0, float x1, float y0, float y1, float k,
               std::shared_ptr<Material> mat) : _x0(x0),
                                                _x1(x1),
                                                _y0(y0),
                                                _y1(y1),
                                                _k(k), _material(mat) {}

bool XYRect::hit(const Ray &r, float t_min, float t_max, HitRecord &rec) const
{
    auto t = (_k - r.origin().z()) / r.direction().z();
    if (t < t_min || t > t_max)
        return false;
    auto x = r.origin().x() + t * r.direction().x();
    auto y = r.origin().y() + t * r.direction().y();
    if (x < _x0 || x > _x1 || y < _y0 || y > _y1)
        return false;
    rec.u = (x - _x0) / (_x1 - _x0);
    rec.v = (y - _y0) / (_y1 - _y0);
    rec.t = t;
    rec.set_face_normal(r, Vector3(0, 0, 1));
    rec.mat = _material;
    rec.p = r.at(t);
    return true;
}
bool XYRect::bounding_box(float t0, float t1, AABB &output_box) const
{
    // The bounding box must have non-zero width in each dimension, so pad the Z
    // dimension a small amount.
    output_box = AABB(Vector3(_x0, _y0, _k - 0.0001), Vector3(_x1, _y1, _k + 0.0001));
    return true;
}

XZRect::XZRect() {}
XZRect::XZRect(float x0, float x1, float z0, float z1, float k,
               std::shared_ptr<Material> mat) : _x0(x0),
                                                _x1(x1),
                                                _z0(z0),
                                                _z1(z1),
                                                _k(k), _material(mat) {}

bool XZRect::hit(const Ray &r, float t_min, float t_max, HitRecord &rec) const
{
    auto t = (_k - r.origin().y()) / r.direction().y();
    if (t < t_min || t > t_max)
        return false;
    auto x = r.origin().x() + t * r.direction().x();
    auto z = r.origin().z() + t * r.direction().z();
    if (x < _x0 || x > _x1 || z < _z0 || z > _z1)
        return false;
    rec.u = (x - _x0) / (_x1 - _x0);
    rec.v = (z - _z0) / (_z1 - _z0);
    rec.t = t;
    rec.set_face_normal(r, Vector3(0, 1, 0));
    rec.mat = _material;
    rec.p = r.at(t);
    return true;
}
bool XZRect::bounding_box(float t0, float t1, AABB &output_box) const
{
    // The bounding box must have non-zero width in each dimension, so pad the Z
    // dimension a small amount.
    output_box = AABB(Vector3(_x0, _k - 0.0001, _z0), Vector3(_x1, _k + 0.0001, _z1));
    return true;
}

YZRect::YZRect() {}
YZRect::YZRect(float y0, float y1, float z0, float z1, float k,
               std::shared_ptr<Material> mat) : _y0(y0),
                                                _y1(y1),
                                                _z0(z0),
                                                _z1(z1),
                                                _k(k), _material(mat) {}

bool YZRect::hit(const Ray &r, float t_min, float t_max, HitRecord &rec) const
{
    auto t = (_k - r.origin().x()) / r.direction().x();
    if (t < t_min || t > t_max)
        return false;
    auto y = r.origin().y() + t * r.direction().y();
    auto z = r.origin().z() + t * r.direction().z();
    if (y < _y0 || y > _y1 || z < _z0 || z > _z1)
        return false;
    rec.u = (y - _y0) / (_y1 - _y0);
    rec.v = (z - _z0) / (_z1 - _z0);
    rec.t = t;
    rec.set_face_normal(r, Vector3(1, 0, 0));
    rec.mat = _material;
    rec.p = r.at(t);
    return true;
}
bool YZRect::bounding_box(float t0, float t1, AABB &output_box) const
{
    // The bounding box must have non-zero width in each dimension, so pad the Z
    // dimension a small amount.
    output_box = AABB(Vector3(_k - 0.0001, _y0, _z0), Vector3(_k + 0.0001, _y1, _z1));
    return true;
}

Box::Box() {}
Box::Box(const Vector3 &p0, const Vector3 &p1, std::shared_ptr<Material> ptr)
{
    _box_min = p0;
    _box_max = p1;

    _sides.add(std::make_shared<XYRect>(p0.x(), p1.x(), p0.y(), p1.y(), p1.z(), ptr));
    _sides.add(std::make_shared<XYRect>(p0.x(), p1.x(), p0.y(), p1.y(), p0.z(), ptr));

    _sides.add(std::make_shared<XZRect>(p0.x(), p1.x(), p0.z(), p1.z(), p1.y(), ptr));
    _sides.add(std::make_shared<XZRect>(p0.x(), p1.x(), p0.z(), p1.z(), p0.y(), ptr));

    _sides.add(std::make_shared<YZRect>(p0.y(), p1.y(), p0.z(), p1.z(), p1.x(), ptr));
    _sides.add(std::make_shared<YZRect>(p0.y(), p1.y(), p0.z(), p1.z(), p0.x(), ptr));
}

bool Box::hit(const Ray &r, float t_min, float t_max, HitRecord &rec) const
{
    return _sides.hit(r, t_min, t_max, rec);
}
bool Box::bounding_box(float t0, float t1, AABB &output_box) const
{
    output_box = AABB(_box_min, _box_max);
    return true;
}