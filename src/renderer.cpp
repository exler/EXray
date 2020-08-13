#include "renderer.hpp"

Vector3 Renderer::lerp(const Ray &ray, const Entity &world, const Vector3 &start_color, const Vector3 &end_color)
{
    HitRecord rec;
    if (world.hit(ray, 0, infinity, rec))
    {
        return 0.5 * (rec.normal + start_color);
    }

    Vector3 unit_direction = unit_vector(ray.direction());
    auto t = 0.5 * (unit_direction.y + 1.0);

    // Linear blend (lerp)
    // blendedValue = (1 - t) * startValue + t * endValue
    return (1.0 - t) * start_color + t * end_color;
}