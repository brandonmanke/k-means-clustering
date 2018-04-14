#include "point2d.h"


Point2D::Point2D(int x, int y) {
    this->x = x;
    this->y = y;
}

//template<class T>
//Point2D<T>::~Point2D() { }

int Point2D::GetX() const {
    return x;
}


int Point2D::GetY() const {
    return y;
}


void Point2D::SetX(const int& x) {
    this->x = x;
}


void Point2D::SetY(const int& y) {
    this->y = y;
}


int Point2D::Sum() const {
    return this->x + this->y;
}