#include "Perlin.hpp"

Perlin::Perlin()
{
    _ranvec = new Vector3[_point_count];
    for (int i = 0; i < _point_count; ++i)
    {
        _ranvec[i] = unit_vector(Vector3::random(-1, 1));
    }

    _perm_x = perlin_generate_perm();
    _perm_y = perlin_generate_perm();
    _perm_z = perlin_generate_perm();
}

Perlin::~Perlin()
{
    delete[] _ranvec;
    delete[] _perm_x;
    delete[] _perm_y;
    delete[] _perm_z;
}

float Perlin::noise(const Vector3 &p) const
{
    auto u = p.x() - floor(p.x());
    auto v = p.y() - floor(p.y());
    auto w = p.z() - floor(p.z());
    int i = floor(p.x());
    int j = floor(p.y());
    int k = floor(p.z());
    Vector3 c[2][2][2];

    for (int di = 0; di < 2; di++)
    {
        for (int dj = 0; dj < 2; dj++)
        {
            for (int dk = 0; dk < 2; dk++)
            {
                c[di][dj][dk] = _ranvec[_perm_x[(i + di) & 255] ^
                                        _perm_y[(j + dj) & 255] ^
                                        _perm_z[(k + dk) & 255]];
            }
        }
    }

    return perlin_interp(c, u, v, w);
}

float Perlin::turbulence(const Vector3 &p, int depth) const
{
    auto accum = 0.0f;
    auto temp_p = p;
    auto weight = 1.0f;

    for (int i = 0; i < depth; i++)
    {
        accum += weight * noise(temp_p);
        weight *= 0.5;
        temp_p *= 2;
    }

    return fabs(accum);
}

int *Perlin::perlin_generate_perm()
{
    auto p = new int[_point_count];

    for (int i = 0; i < _point_count; i++)
        p[i] = i;

    permute(p, _point_count);
    return p;
}

void Perlin::permute(int *p, int n)
{
    for (int i = n - 1; i > 0; i--)
    {
        int target = random_int(0, i);
        int tmp = p[i];
        p[i] = p[target];
        p[target] = tmp;
    }
}