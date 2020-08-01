#include "image_writer.hpp"
#include "vector3.hpp"

int main()
{
    const int image_width = 256;
    const int image_height = 256;

    ImageWriter iw(image_width, image_height);

    for (int j = image_height - 1; j >= 0; --j)
    {
        for (int i = 0; i < image_width; ++i)
        {
            Vector3 colors(double(i) / (image_width - 1), double(j) / (image_height - 1), 0.25);

            iw.write(colors.r(), colors.g(), colors.b());
        }
    }
    return 0;
}