#include "image_writer.hpp"

ImageWriter::ImageWriter(const int imageWidth, const int imageHeight, const std::string filename)
{
    _imageStream.open(filename, std::ios_base::trunc);

    // "P3" means this is a RGB color image in ASCII
    // "255" is the maximum value for each color
    _imageStream << "P3\n";
    _imageStream << imageWidth << " " << imageHeight << "\n255\n";
}

ImageWriter &ImageWriter::operator<<(const std::string str)
{
    _imageStream << str;
    return *this;
}

ImageWriter &ImageWriter::operator<<(const char chr)
{
    _imageStream << chr;
    return *this;
}

ImageWriter &ImageWriter::operator<<(const int val)
{
    _imageStream << val;
    return *this;
}

ImageWriter::~ImageWriter()
{
    _imageStream.close();
}