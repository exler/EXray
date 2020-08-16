#include "scene.hpp"

Scene::Scene(float aspect_ratio, int image_width) : _image_width(image_width)
{
    _image_height = static_cast<int>(image_width / aspect_ratio);
}

Scene::Scene(int image_width, int image_height) : _image_width(image_width),
                                                  _image_height(image_height) {}

void Scene::set_camera(Camera *camera)
{
    _camera = camera;
}
void Scene::set_world(EntityList *world)
{
    _world = world;
}
void Scene::set_samples_per_pixel(const int samples_per_pixel)
{
    _samples_per_pixel = samples_per_pixel;
}

Vector3 Scene::lerp(const Ray &ray, const Vector3 &start, const Vector3 &end) const
{
    HitRecord rec;
    if (_world->hit(ray, 0, infinity, rec))
    {
        return 0.5 * (rec.normal + start);
    }

    Vector3 unit_direction = unit_vector(ray.direction());
    auto t = 0.5 * (unit_direction.y + 1.0);

    // Linear blend (lerp)
    // blendedValue = (1 - t) * startValue + t * endValue
    return (1.0 - t) * start + t * end;
}

Color3 Scene::transform_color(Vector3 &color) const
{
    auto r = color.r();
    auto g = color.g();
    auto b = color.b();

    auto scale = 1.0 / _samples_per_pixel;
    r *= scale;
    g *= scale;
    b *= scale;

    return Color3(
        static_cast<int>(256 * std::clamp(r, 0.0f, 0.999f)),
        static_cast<int>(256 * std::clamp(g, 0.0f, 0.999f)),
        static_cast<int>(256 * std::clamp(b, 0.0f, 0.999f)));
}

void Scene::render()
{
    // Render
    for (int j = _image_height - 1; j >= 0; --j)
    {
        for (int i = 0; i < _image_width; ++i)
        {
            Color3 pixel_color(0, 0, 0);
            for (int s = 0; s < _samples_per_pixel; ++s)
            {
                auto u = (i + random_float()) / (_image_width - 1);
                auto v = (j + random_float()) / (_image_height - 1);
                Ray r = _camera->get_ray(u, v);
                pixel_color += lerp(r, Vector3(1.0, 1.0, 1.0), Vector3(0.5, 0.7, 1.0));
            }
            _image.push_back(transform_color(pixel_color));
        }
    }
}

void Scene::save(const std::string filename)
{
    ImageWriter iw(_image_width, _image_height, filename);

    for (unsigned int i = 0; i < _image.size(); i++)
    {
        iw.write(_image[i].r(), _image[i].g(), _image[i].b());
    }

    std::cout << "[EXRay] Image saved to: " << filename << std::endl;
}