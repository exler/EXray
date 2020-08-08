#include "image.hpp"
#include "image_writer.hpp"
#include "vector3.hpp"
#include "ray.hpp"

int main()
{
    Image img(428);
    ImageWriter iw(img);

    for (int j = img.get_image_height() - 1; j >= 0; --j)
    {
        for (int i = 0; i < img.get_image_width(); ++i)
        {
            auto u = double(i) / (img.get_image_width() - 1);
            auto v = double(j) / (img.get_image_height() - 1);
            Ray r(img.get_origin(), img.lower_left_corner() + u * img.get_horizontal() + v * img.get_vertical() - img.get_origin());
            Vector3 pixel_color = r.lerp(Vector3(1.0, 1.0, 1.0), Vector3(1.0, 0.2, 0.2));

            iw.write(pixel_color.r(), pixel_color.g(), pixel_color.b());
        }
    }
    return 0;
}