#include "Sphere.hpp"

Sphere::Sphere() {}
Sphere::Sphere(Vector3 c, float r, std::shared_ptr<Material> m) : _center(c),
                                                                  _radius(r),
                                                                  _material(m) {}

bool Sphere::hit(const Ray &r, float t_min, float t_max, HitRecord &rec) const
{
    Vector3 oc = r.origin() - _center;
    auto a = r.direction().length_squared();
    auto half_b = dot(oc, r.direction());
    auto c = oc.length_squared() - _radius * _radius;
    auto delta = half_b * half_b - a * c;

    if (delta > 0)
    {
        auto root = sqrt(delta);

        auto tmp = (-half_b - root) / a;
        if (tmp < t_max && tmp > t_min)
        {
            rec.t = tmp;
            rec.p = r.at(rec.t);
            Vector3 outward_normal = (rec.p - _center) / _radius;
            rec.set_face_normal(r, outward_normal);
            Sphere::get_sphere_uv((rec.p - _center) / _radius, rec.u, rec.v);
            rec.mat = _material;
            return true;
        }

        tmp = (-half_b + root) / a;
        if (tmp < t_max && tmp > t_min)
        {
            rec.t = tmp;
            rec.p = r.at(rec.t);
            Vector3 outward_normal = (rec.p - _center) / _radius;
            rec.set_face_normal(r, outward_normal);
            Sphere::get_sphere_uv((rec.p - _center) / _radius, rec.u, rec.v);
            rec.mat = _material;
            return true;
        }
    }

    return false;
}

bool Sphere::bounding_box(float t0, float t1, AABB &output_box) const
{
    output_box = AABB(
        _center - Vector3(_radius, _radius, _radius),
        _center + Vector3(_radius, _radius, _radius));
    return true;
}

void Sphere::get_sphere_uv(const Vector3 &p, float &u, float &v)
{
    auto phi = atan2(p.z(), p.x());
    auto theta = asin(p.y());
    u = 1 - (phi + pi) / (2 * pi);
    v = (theta - pi / 2) / pi;
}