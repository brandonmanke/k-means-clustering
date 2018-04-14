#ifndef POINT3D_H
#define POINT3D_H

#include "point2d.h"

//template<class T>
class Point3D : public Point2D {
public:
    Point3D(int x, int y, int z) : Point2D(x, y), z(z) { }
    //~Point3D();
    int GetZ() const;
    void SetZ(const int& z);
    int Sum() const;
private:
    int z;
};

#endif