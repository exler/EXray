#include "ImageWriter.hpp"

ImageWriter::ImageWriter(const int image_width, const int image_height, const std::string filename)
{
    _image_stream.open(filename, std::ios_base::trunc);

    // "P3" means this is a RGB color image in ASCII
    // "255" is the maximum value for each color
    _image_stream << "P3\n";
    _image_stream << image_width << " " << image_height << "\n255\n";
}

ImageWriter &ImageWriter::operator<<(const std::string str)
{
    _image_stream << str;
    return *this;
}

ImageWriter &ImageWriter::operator<<(const char chr)
{
    _image_stream << chr;
    return *this;
}

ImageWriter &ImageWriter::operator<<(const int val)
{
    _image_stream << val;
    return *this;
}

ImageWriter &ImageWriter::write(const int r, const int g, const int b)
{
    _image_stream << r << ' ' << g << ' ' << b << std::endl;
    return *this;
}

ImageWriter::~ImageWriter()
{
    _image_stream.close();
}