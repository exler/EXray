<p align="center">
    <img src="docs/logo_transparent.png" width="324">
    <p align="center">🎥 Simple, multithreaded, extensible 3D raytracing engine written in C++17</P>
    <p align="center">
        <img src="https://github.com/EXLER/EXray/workflows/Build/badge.svg">
        <img src="https://img.shields.io/github/license/EXLER/EXRay">
        <img src="https://img.shields.io/github/repo-size/EXLER/EXRay">
    </p>
</p>

## Dependencies

* [stb_image.h](https://github.com/nothings/stb) - image loading

## Installation

### Building from source

```bash
# Recursively clone the repository to get all submodules
$ git clone --recurse-submodules https://github.com/EXLER/EXray

# Create build directory and build project
$ mkdir EXray/build/ && cd EXRAY/build/
$ cmake .. && make
```

## Usage

```bash
$ ./exray
```

If you want to convert the output PPM file, use [ImageMagick](https://imagemagick.org/index.php)
```bash
$ magick image.ppm image.png
```

## License

Copyright (c) 2020 by ***Kamil Marut***

`EXray` is under the terms of the [MIT License](https://www.tldrlegal.com/l/mit), following all clarifications stated in the [license file](LICENSE).