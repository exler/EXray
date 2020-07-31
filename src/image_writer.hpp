#ifndef IMAGE_WRITER_H
#define IMAGE_WRITER_H

#include <iostream>
#include <fstream>
#include <string>

class ImageWriter
{
public:
    ImageWriter(const int imageWidth, const int imageHeight, const std::string filename = "image.ppm");
    ~ImageWriter();

    ImageWriter &operator<<(const std::string str);
    ImageWriter &operator<<(const char chr);
    ImageWriter &operator<<(const int val);

private:
    std::ofstream _imageStream;
};

#endif