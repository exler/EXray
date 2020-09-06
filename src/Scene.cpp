#include "Scene.hpp"

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
void Scene::set_max_depth(const int max_depth)
{
    _max_depth = max_depth;
}

Vector3 Scene::lerp(const Ray &ray, const Vector3 &start, const Vector3 &end, int depth) const
{
    HitRecord rec;

    if (depth <= 0)
        return Color3(0, 0, 0);

    if (_world->hit(ray, 0.001, infinity, rec))
    {
        Ray scattered;
        Color3 attenuation;
        if (rec.mat->scatter(ray, rec, attenuation, scattered))
            return attenuation * lerp(scattered, start, end, depth - 1);
        return Color3(0, 0, 0);
    }

    Vector3 unit_direction = unit_vector(ray.direction());
    auto t = 0.5 * (unit_direction.y() + 1.0);

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
    r = sqrt(scale * r);
    g = sqrt(scale * b);
    b = sqrt(scale * b);

    return Color3(
        static_cast<int>(256 * clamp(r, 0.0f, 0.999f)),
        static_cast<int>(256 * clamp(g, 0.0f, 0.999f)),
        static_cast<int>(256 * clamp(b, 0.0f, 0.999f)));
}

void Scene::render()
{
    auto t1 = std::chrono::high_resolution_clock::now();
    for (int j = _image_height - 1; j >= 0; --j)
    {
        std::cout << "Scanlines remaining: " << j << std::endl;
        for (int i = 0; i < _image_width; ++i)
        {
            Color3 pixel_color(0, 0, 0);
            for (int s = 0; s < _samples_per_pixel; ++s)
            {
                auto u = (i + random_float()) / (_image_width - 1);
                auto v = (j + random_float()) / (_image_height - 1);
                Ray r = _camera->get_ray(u, v);
                pixel_color += lerp(r, Vector3(1.0, 1.0, 1.0), Vector3(0.5, 0.7, 1.0), _max_depth);
            }
            _image.push_back(transform_color(pixel_color));
        }
    }
    auto t2 = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::seconds>(t2 - t1).count();

    std::cout << "Finished rendering in " << duration << "s." << std::endl;
}

void Scene::save(const std::string filename)
{
    ImageWriter iw(_image_width, _image_height, filename);

    for (Vector3 pixel : _image)
    {
        iw.write(pixel.r(), pixel.g(), pixel.b());
    }

    std::cout << "Image saved to: " << filename << std::endl;
}