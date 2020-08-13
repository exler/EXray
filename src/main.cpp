#include "utility.hpp"
#include "image.hpp"
#include "image_writer.hpp"
#include "renderer.hpp"

#include "entity.hpp"
#include "entities/sphere.hpp"

int main()
{
    // Image
    Image img(428);
    ImageWriter iw(img);

    // World
    EntityList world;
    world.add(std::make_shared<Sphere>(Vector3(0, 0, -1), 0.5));
    world.add(std::make_shared<Sphere>(Vector3(0, -100.5, -1), 100));

    // Render
    for (int j = img.get_image_height() - 1; j >= 0; --j)
    {
        for (int i = 0; i < img.get_image_width(); ++i)
        {
            auto u = double(i) / (img.get_image_width() - 1);
            auto v = double(j) / (img.get_image_height() - 1);
            Ray r(img.get_origin(), img.lower_left_corner() + u * img.get_horizontal() + v * img.get_vertical() - img.get_origin());
            Vector3 pixel_color = Renderer::lerp(r, world, Vector3(1.0, 1.0, 1.0), Vector3(0.0, 0.5, 1.0));

            iw.write(pixel_color.r(), pixel_color.g(), pixel_color.b());
        }
    }
    return 0;
}