#include "point3d.h"

//template<class T>
//Point3D<T>::~Point3D() { }

int Point3D::GetZ() const {
    return this->z;
}

void Point3D::SetZ(const int& z) {
    this->z = z;
}

int Point3D::Sum() const {
    return Point2D::Sum() + this->z;
}