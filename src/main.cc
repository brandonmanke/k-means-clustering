/**
 * K Means Clustering implementation in C++
 */
#include <iostream>
#include "point2d.h"
#include "point3d.h"

int main(void) {
    std::cout << std::endl;
    Point2D::Point2D point(1, 2);
    std::cout << "Point2D Info:" << std::endl
              << "X Value: " << point.GetX() << std::endl
              << "Y Value: " << point.GetY() << std::endl
              << "Sum: " << point.Sum() << std::endl;
              //<< "Z Value: " << point.GetZ() << std::endl
    
    Point3D::Point3D point2(3, 4, 6);
    std::cout << "Point3D Info:" << std::endl
              << "X Value: " << point2.GetX() << std::endl
              << "Y Value: " << point2.GetY() << std::endl
              << "Z Value: " << point2.GetZ() << std::endl
              << "Sum: " << point2.Sum() << std::endl;
    std::cout << std::endl;
    return 0;
}
