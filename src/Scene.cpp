#include "Scene.hpp"

Scene::Scene(int image_width, int image_height) : _image_width(image_width),
                                                  _image_height(image_height)
{
    _image = new Color3[_image_width * _image_height];
}
Scene::~Scene()
{
    delete _image;
}

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
void Scene::set_background(const Color3 &background)
{
    _background = background;
}
void Scene::set_thread_count(const int thread_count)
{
    _thread_count = thread_count;
}

Vector3 Scene::ray_color(const Ray &ray, int depth) const
{
    HitRecord rec;

    if (depth <= 0)
        return Color3(0, 0, 0);

    if (!_world->check_objects_hit(ray, 0.001, infinity, rec))
        return _background;

    Ray scattered;
    Color3 attenuation;
    Color3 emitted = rec.mat->emitted(rec.u, rec.v, rec.p);

    if (!rec.mat->scatter(ray, rec, attenuation, scattered))
        return emitted;

    return emitted + attenuation * ray_color(scattered, depth - 1);
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
        static_cast<int>(256 * std::clamp(r, 0.0f, 0.999f)),
        static_cast<int>(256 * std::clamp(g, 0.0f, 0.999f)),
        static_cast<int>(256 * std::clamp(b, 0.0f, 0.999f)));
}

Color3 Scene::render_pixel(int i, int j)
{
    Color3 pixel(0, 0, 0);
    for (int s = 0; s < _samples_per_pixel; s++)
    {
        auto u = (i + random_float()) / (_image_width);
        auto v = (j + random_float()) / (_image_height);
        Ray r = _camera->get_ray(u, v);
        pixel += ray_color(r, _max_depth);
    }

    return pixel;
}

void Scene::render_tile(int tile_height, int tile_height_pos)
{
    for (int j = tile_height_pos; j < tile_height_pos + tile_height; ++j)
    {
        for (int i = 0; i < _image_width; ++i)
        {
            Color3 pixel_color = render_pixel(i, j);

            int idx = j * _image_width + i;
            _image[idx] = transform_color(pixel_color);
        }
    }
}

void Scene::render()
{
    std::vector<std::thread> threads;
    auto t1 = std::chrono::high_resolution_clock::now();

    std::cout << "Running the renderer with thread count: " << _thread_count << std::endl;
    int tile_height = _image_height / _thread_count;
    for (int th = 0, sum = 0; th < _thread_count; ++th)
    {
        sum += tile_height;
        int tile_height_pos = tile_height * th;
        if (th == (_thread_count - 1) && sum != _image_height)
            tile_height = _image_height - tile_height_pos;

        threads.push_back(std::thread(&Scene::render_tile, this, tile_height, tile_height_pos));
    }

    for (auto &t : threads)
    {
        if (t.joinable())
            t.join();
    }
    auto t2 = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::seconds>(t2 - t1).count();

    std::cout << "Finished rendering in " << duration << "s." << std::endl;
}

void Scene::save(const std::string filename)
{
    std::cout << "Writing image to file..." << std::endl;
    ImageWriter iw(_image_width, _image_height, filename);

    for (int i = _image_height * _image_width; i > 0; --i)
    {
        iw.write(_image[i].r(), _image[i].g(), _image[i].b());
    }

    std::cout << "Image saved to: " << filename << std::endl;
}
