#include "matrix.h"

Matrix::Matrix() {
    std::vector<Point::Point> empty;
    this->rowCount = 0;
    this->colCount = 0;
    this->matrix = empty;
}

Matrix::Matrix(const std::vector<Point::Point> matrix) {
    bool isMatrix = true;
    int dimension = 0;
    if (matrix.size() > 0) {
        dimension = matrix.at(0).GetDimension();
        for (int i = 1; i < matrix.size(); i++) {
            if (matrix.at(i).GetDimension() != dimension) {
                isMatrix = false;
            }
        }
    }
    if (isMatrix) {
        this->matrix = matrix;
        this->rowCount = dimension;
        this->colCount = matrix.size();
    }
}

Matrix Matrix::GenerateRandomMatrix(const int row, const int col) {
    // rows = dimensions
    // cols = number of points
    std::vector<Point::Point> cols;
    Point p;
    for (int i = 0; i < col; i++) {
        p = p.RandomPoint(row);
        cols.push_back(p);
    }
    Matrix::Matrix m(cols);
    return m;
}

Clusters Matrix::KMeansClustering(const int k) const {
    // We could just make the centroids a random matrix?
    std::vector<Point::Point> centroids(k);
    // place k centroids
    Point::Point p;
    for (int i = 0; i < centroids.size(); i++) {
        // randomly generate points (make sure same dimensions as matrix)
        centroids.at(i) = p.RandomPoint(this->rowCount);
    }

    Clusters clust(k);
    // initialize each cluster with empty list
    for (int i = 0; i < k; i++) {
        std::vector<Point::Point> cluster;
        clust.at(i) = cluster;
    } 

    for (int i = 0; i < this->matrix.size(); i++) {
        Point::Point p = this->matrix.at(i);
        int minDistance = std::numeric_limits<int>::max();
        int minCentroidIndex = -1;
        // find minimum distance between point and every centroid
        for (int j = 0; j < centroids.size(); j++) {
            int dist = p.Distance(centroids.at(j));
            if (dist < minDistance) {
                minDistance = dist;
                minCentroidIndex = j;
            }
        }
        clust.at(minCentroidIndex).push_back(p); // add point to cluster
    }

    // for each cluster we find new centroids
    // as the mean of all points in each cluster
    //for (int i = 0; i < k; i++) {

    //}

    return clust;
}

std::string Matrix::ToString() const {
    std::stringstream ss;
    for (int i = 0; i < this->matrix.size(); i++) {
        ss << "[ ";
        Point p = this->matrix.at(i);
        int dimension = p.GetDimension();
        for (int j = 0; j < dimension - 1; j++) {
            //std::cout << p.GetIndex(j);
            ss << p.GetIndex(j) << ", ";
        }
        ss << this->matrix.at(i).GetIndex(dimension - 1) << " ]\n";
    }
    std::string str = ss.str();
    return str;
}
