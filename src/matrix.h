#ifndef MATRIX_H
#define MATRIX_H

#include "point.h"
#include <vector>
#include <limits>
#include <sstream>
#include <iostream>

// This just makes it easier to differentiate matrices and clusters
// Even though they are pretty much the same thing (from a type perspective).
// Although Clusters do not necessarily have all rows of the same length
typedef std::vector<std::vector<Point>> Clusters;

class Matrix {
public:
    Matrix();
    Matrix(const std::vector<Point> matrix);
    Matrix GenerateRandomMatrix(const int row, const int col);
    //~Matrix();
    Clusters KMeansClustering(const int k, const int limit) const;
    int ClassifyPoint(const Point& p, const Clusters& clust) const;
    std::string ToString() const;
private:
    int rowCount;
    int colCount;
    std::vector<Point> matrix;
    std::vector<Point> RandomCentroids(const int k) const;
    Clusters ClusterPoints(const int k, const std::vector<Point>& centroids) const;
    std::vector<Point> AverageClusters(const int k, 
                                       const Clusters& clust, 
                                       const std::vector<Point>& centroids) const;
};

#endif
