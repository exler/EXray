#ifndef PERLIN_H
#define PERLIN_H

#include <cmath>

#include "Vector3.hpp"
#include "Utility.hpp"

class Perlin
{
public:
    Perlin();
    ~Perlin();

    float noise(const Vector3 &p) const;
    float turbulence(const Vector3 &p, int depth = 7) const;

private:
    static const int _point_count = 256;
    Vector3 *_ranvec;
    int *_perm_x;
    int *_perm_y;
    int *_perm_z;

    static int *perlin_generate_perm();
    static void permute(int *p, int n);
};

inline float perlin_interp(Vector3 c[2][2][2], float u, float v, float w)
{
    // Hermitian smoothing
    // https://en.wikipedia.org/wiki/Cubic_Hermite_spline
    auto uu = u * u * (3 - 2 * u);
    auto vv = v * v * (3 - 2 * v);
    auto ww = w * w * (3 - 2 * w);
    auto accum = 0.0f;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            for (int k = 0; k < 2; k++)
            {
                Vector3 weight_v(u - i, v - j, w - k);
                accum += (i * uu + (1 - i) * (1 - uu)) *
                         (j * vv + (1 - j) * (1 - vv)) *
                         (k * ww + (1 - k) * (1 - ww)) *
                         dot(c[i][j][k], weight_v);
            }
        }
    }

    return accum;
}

#endif