/**
 * K Means Clustering implementation in C++
 * 
 * Consider making Point2D and Point3D into one combined class for N-Dimensional Points
 */
#include <iostream>
#include "point.h"

int main(void) {
    std::cout << std::endl;

    Point::Point point3(3, 4, 6);
    std::cout << "Point2D Info:" << std::endl
              << "X Value: " << point3.GetIndex(0) << std::endl
              << "Y Value: " << point3.GetIndex(1) << std::endl
              << "Z Value: " << point3.GetIndex(2) << std::endl;
    std::cout << std::endl;

    Point::Point p1(3, 4, 1);
    std::cout << "Point3D Info:" << std::endl
              << "X Value: " << p1.GetIndex(0) << std::endl
              << "Y Value: " << p1.GetIndex(1) << std::endl
              << "Z Value: " << p1.GetIndex(2) << std::endl;
    std::cout << std::endl;

    Point::Point p2(6, 0, 2);
    std::cout << "Point3D Info:" << std::endl
              << "X Value: " << p2.GetIndex(0) << std::endl
              << "Y Value: " << p2.GetIndex(1) << std::endl
              << "Z Value: " << p2.GetIndex(2) << std::endl;
    std::cout << std::endl;

    std::cout << "Distance between 2 points (p1,p2): " << p1.Distance(p2) << std::endl;
    std::cout << "Distance between 2 points (p2,p1): " << p2.Distance(p1) << std::endl;
    std::cout << std::endl;

    std::vector<int> v = { 1, 2, 3, 4, 5, 6 };
    Point::Point point5(v);
    std::cout << "Point Info:" << std::endl
              << "Dimension: " << point5.GetDimension() << std::endl
              << "X Value: " << point5.GetIndex(0) << std::endl
              << "Y Value: " << point5.GetIndex(1) << std::endl
              << "Z Value: " << point5.GetIndex(2) << std::endl
              << "4 Value: " << point5.GetIndex(3) << std::endl
              << "5 Value: " << point5.GetIndex(4) << std::endl
              << "6 Value: " << point5.GetIndex(5) << std::endl;
    std::cout << std::endl;
    return 0;
}
