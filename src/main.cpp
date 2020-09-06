#include "Utility.hpp"
#include "Camera.hpp"
#include "Scene.hpp"

#include "EntityList.hpp"
#include "entities/MovingSphere.hpp"
#include "entities/Sphere.hpp"
#include "materials/Dielectric.hpp"
#include "materials/Diffuse.hpp"
#include "materials/Metal.hpp"
#include "textures/Checker.hpp"

EntityList random_scene()
{
    EntityList world;

    auto checker = std::make_shared<Checker>(Color3(0.2, 0.3, 0.1), Color3(0.9, 0.9, 0.9));
    world.add(std::make_shared<Sphere>(Color3(0, -1000, 0), 1000, std::make_shared<Diffuse>(checker)));

    for (int a = -11; a < 11; a++)
    {
        for (int b = -11; b < 11; b++)
        {
            auto choose_mat = random_float();
            Color3 center(a + 0.9 * random_float(), 0.2, b + 0.9 * random_float());

            if ((center - Color3(4, 0.2, 0)).length() > 0.9)
            {
                std::shared_ptr<Material> sphere_material;

                if (choose_mat < 0.8)
                {
                    // diffuse
                    auto albedo = Color3::random() * Color3::random();
                    sphere_material = std::make_shared<Diffuse>(albedo);
                    auto center2 = center + Vector3(0, random_float(0, 0.5), 0);
                    world.add(std::make_shared<MovingSphere>(center, center2, 0.0, 1.0, 0.2, sphere_material));
                }
                else if (choose_mat < 0.95)
                {
                    // metal
                    auto albedo = Color3::random(0.5, 1);
                    auto fuzz = random_float(0, 0.5);
                    sphere_material = std::make_shared<Metal>(albedo, fuzz);
                    world.add(std::make_shared<Sphere>(center, 0.2, sphere_material));
                }
                else
                {
                    // glass
                    sphere_material = std::make_shared<Dielectric>(1.5);
                    world.add(std::make_shared<Sphere>(center, 0.2, sphere_material));
                }
            }
        }
    }

    auto material1 = std::make_shared<Dielectric>(1.5);
    world.add(std::make_shared<Sphere>(Vector3(0, 1, 0), 1.0, material1));

    auto material2 = std::make_shared<Diffuse>(Color3(0.4, 0.2, 0.1));
    world.add(std::make_shared<Sphere>(Vector3(-4, 1, 0), 1.0, material2));

    auto material3 = std::make_shared<Metal>(Color3(0.7, 0.6, 0.5), 0.0);
    world.add(std::make_shared<Sphere>(Vector3(4, 1, 0), 1.0, material3));

    return world;
}

int main()
{
    // Details
    float aspect_ratio = 16.0 / 9.0;
    int image_width = 400;
    Vector3 lookfrom(13, 2, 3);
    Vector3 lookat(0, 0, 0);
    Vector3 vup(0, 1, 0);
    auto dist_to_focus = 10;
    auto aperture = 0.1;

    // Camera
    Camera cam(aspect_ratio, 20, lookfrom, lookat, vup, aperture, dist_to_focus, 0.0, 1.0);

    // World
    EntityList world = random_scene();

    // Scene (image)
    Scene scene(aspect_ratio, image_width);
    scene.set_camera(&cam);
    scene.set_world(&world);

    scene.render();
    scene.save();

    return 0;
}