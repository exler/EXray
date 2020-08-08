#ifndef IMAGE_WRITER_H
#define IMAGE_WRITER_H

#include <iostream>
#include <fstream>
#include <string>

#include "image.hpp"

class ImageWriter
{
public:
    ImageWriter(const int imageWidth, const int imageHeight, const std::string filename = "image.ppm");
    ImageWriter(const Image &image, const std::string filename = "image.ppm");
    ~ImageWriter();

    ImageWriter &operator<<(const std::string str);
    ImageWriter &operator<<(const char chr);
    ImageWriter &operator<<(const int val);

    ImageWriter &write(const int r, const int g, const int b);

private:
    std::ofstream _imageStream;
};

#endif