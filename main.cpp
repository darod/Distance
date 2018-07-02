#include <iostream>
#include "Vec3D.hpp"

using namespace Autodesk;

template <typename T>
T distanceFromPointToLineSegment(Vec3D<T> linePointA, Vec3D<T> linePointB, Vec3D<T> pointC)
{
    auto vecAB = linePointB.sub(linePointA);
    auto vecAC = pointC.sub(linePointA);

    if(vecAC.dot(vecAB) <= 0.0)
    {
        return vecAC.length();
    }

    auto vecBC = pointC.sub(linePointB);
    if(vecBC.dot(vecAB) >= 0.0)
    {
        return vecBC.length();
    }

    return vecAB.cross(vecAC).length() / vecAB.length();
}

int main()
{
	Vec3D<double> A(12.0, 12.0, 12.0);
	Vec3D<double> B(22.0, 22.0, 22.0);
	Vec3D<double> C(18.0, 18.0, 50.0);

    std::cout << "Distance: " << distanceFromPointToLineSegment(A, B, C); 

    return 0;
}
