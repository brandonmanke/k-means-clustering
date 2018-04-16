#ifndef MATRIX_H
#define MATRIX_H

#include "point.h"
#include <vector>
#include <limits>
#include <sstream>
#include <iostream>
//#include <unordered_map>

// This just makes it easier to differentiate types and clusters
// Even though they are pretty much the same thing.
// Although Clusters do not necessarily have all rows of the same length
typedef std::vector<std::vector<Point::Point>> Clusters;

// Do I even need a matrix? I am pretty sure I dont lmfao
class Matrix {
public:
    Matrix();
    Matrix(const std::vector<Point::Point> matrix);
    Matrix GenerateRandomMatrix(const int row, const int col);
    //~Matrix();
    Clusters KMeansClustering(const int k) const;
    Clusters KMeansClustering(const int k, Matrix centroids, Clusters c) const;
    std::string ToString() const;
private:
    int rowCount;
    int colCount;
    std::vector<Point::Point> matrix;
};

#endif
