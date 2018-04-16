#ifndef POINT_H
#define POINT_H

#include <vector>
#include <cmath>
#include <iostream>
#include <sstream>

class Point {
public:
    Point();
    Point(const std::vector<int> vec);
    //Point(const int dimensions);
    Point(const int x, const int y);
    Point(const int x, const int y, const int z);
    Point Sum(const Point& point) const;
    // Euclidean distance
    int Distance(const Point& point) const;
    std::vector<int> GetVector() const;
    int GetIndex(const int index) const;
    int SetIndex(const int index, const int val);
    int GetDimension() const;
    std::string ToString() const;
    Point RandomPoint(const int dimension);
private:
    std::vector<int> vec;
    int dimension;
};

#endif
