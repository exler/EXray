#include "Utility.hpp"
#include "Camera.hpp"
#include "Scene.hpp"

#include "Entity.hpp"
#include "entities/Sphere.hpp"

int main()
{
    // Details
    float aspect_ratio = 16.0 / 9.0;
    int image_width = 400;

    // Camera
    Camera cam(aspect_ratio);

    // World
    EntityList world;
    world.add(std::make_shared<Sphere>(Vector3(0, 0, -1), 0.5));
    world.add(std::make_shared<Sphere>(Vector3(0, -100.5, -1), 100));

    // Scene (image)
    Scene scene(aspect_ratio, image_width);
    scene.set_camera(&cam);
    scene.set_world(&world);

    scene.render();
    scene.save();

    return 0;
}