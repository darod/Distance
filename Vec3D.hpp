#pragma once
#include <vector>
#include <numeric>
#include <complex>

namespace Autodesk
{

template <typename T>
class Vec3D
{
    std::vector<T> points;

public:
    Vec3D(T x, T y, T z): points{x, y, z} {}

    Vec3D sub(const Vec3D& v)
    {
        return { points[0] - v.points[0],
                 points[1] - v.points[1],
                 points[2] - v.points[2] };
    }

    T dot(const Vec3D& v)
    {
        return std::inner_product(points.begin(), points.end(), v.points.begin(), 0.0);
    }

    Vec3D cross(const Vec3D& v)
    {
        return { points[1] * v.points[2] - points[2] * v.points[1],
                 points[0] * v.points[2] - points[2] * v.points[0],
                 points[0] * v.points[1] - points[1] * v.points[0] };
    }

    T length()
    {
        return std::sqrt(points[0]*points[0] + points[1]*points[1] + points[2]*points[2]);
    }
};

}
