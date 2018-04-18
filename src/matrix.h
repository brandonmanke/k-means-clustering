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

class Matrix {
public:
    Matrix();
    Matrix(const std::vector<Point::Point> matrix);
    Matrix GenerateRandomMatrix(const int row, const int col);
    //~Matrix();
    Clusters KMeansClustering(const int k, const int limit) const;
    std::string ToString() const;
private:
    int rowCount;
    int colCount;
    std::vector<Point::Point> matrix;
    std::vector<Point::Point> RandomCentroids(const int k) const;
    Clusters ClusterPoints(const int k, const std::vector<Point::Point>& centroids) const;
    std::vector<Point::Point> AverageClusters(const int k, 
                                              const Clusters& clust, 
                                              const std::vector<Point::Point>& centroids) const;
};

#endif
