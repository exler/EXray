#ifndef IMAGE_WRITER_H
#define IMAGE_WRITER_H

#include <iostream>
#include <fstream>
#include <string>

#include "Scene.hpp"

class ImageWriter
{
public:
    ImageWriter(const int image_width, const int image_height, const std::string filename);
    ~ImageWriter();

    ImageWriter &operator<<(const std::string str);
    ImageWriter &operator<<(const char chr);
    ImageWriter &operator<<(const int val);

    ImageWriter &write(const int r, const int g, const int b);

private:
    std::ofstream _image_stream;
};

#endif