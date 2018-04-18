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

/**
 * Generate k random centroids
 */
std::vector<Point::Point> Matrix::RandomCentroids(const int k) const {
    std::vector<Point::Point> centroids(k);
    // place k centroids
    Point::Point p;
    for (int i = 0; i < k; i++) {
        // randomly generate points (make sure same dimensions as matrix)
        centroids.at(i) = p.RandomPoint(this->rowCount);
    }
    return centroids;
} 

/**
 * Group Points into clusters based off centroids
 */ 
Clusters Matrix::ClusterPoints(const int k, const std::vector<Point::Point>& centroids) const {
    Clusters clust(k);
    // initialize each cluster with empty list
    for (int i = 0; i < k; i++) {
        std::vector<Point::Point> cluster;
        clust.at(i) = cluster;
    } 

    // Clusters c, centroids
    for (int i = 0; i < this->matrix.size(); i++) {
        Point::Point p = this->matrix.at(i);
        int minDistance = std::numeric_limits<int>::max();
        int minCentroidIndex = -1;
        // find minimum distance between point and every centroid
        for (int j = 0; j < k; j++) {
            int dist = p.Distance(centroids.at(j));
            if (dist < minDistance) {
                minDistance = dist;
                minCentroidIndex = j;
            }
        }
        clust.at(minCentroidIndex).push_back(p); // add point to cluster
    }
    return clust;
}

// not sure if references are the best idea idk?
// I mean we are only reading these inputs so..
// return reference?
/**
 * Calculate new centroids, based on average of clusters
 */
std::vector<Point::Point> Matrix::AverageClusters(const int k, 
                                          const Clusters& clust, 
                                          const std::vector<Point::Point>& centroids) const {
    std::vector<Point::Point> newCentroids(k);
    for (int i = 0; i < k; i++) {
        std::vector<Point::Point> cluster = clust.at(i);
        if (cluster.size() != 0) {
            int dimension = cluster.at(0).GetDimension();
            Point::Point sum(dimension); // since we can only add Points of same dimension
            for (int j = 0; j < cluster.size() - 1; j++) {
                Point::Point current = cluster.at(j);
                sum = sum + current;
            }
            // since we are using ints right now this isn't as accurate
            Point::Point average = sum.Shrink(cluster.size());
            // Replace new averaged centroid
            newCentroids.at(i) = average;
        } else {
            // we just use the old centroid
            newCentroids.at(i) = centroids.at(i);
        }
    }
    return newCentroids;
}

void PrintClusters(const Clusters& c) {
    for (int i = 0; i < c.size(); i++) {
        std::cout << "Cluster " << i << ": " << std::endl;
        for (int j = 0; j < c.at(i).size(); j++) {
            Point::Point p = c.at(i).at(j);
            std::cout << "Point: " << j << " - "
                      << p.ToString() << std::endl;
        }
        std::cout << std::endl;
    }
}

Clusters Matrix::KMeansClustering(const int k, const int limit) const {
    std::vector<Point::Point> centroids = RandomCentroids(k);
    Clusters clust = ClusterPoints(k, centroids);

    // for each cluster we find new centroids
    // as the mean of all points in each cluster
    centroids = AverageClusters(k, clust, centroids);

    int iterations = 0;
    while(iterations < limit) {
        clust = ClusterPoints(k, centroids);
        centroids = AverageClusters(k, clust, centroids);
        iterations++;
        std::cout << std::endl << "Iteration " << iterations << ": " << std::endl;
        PrintClusters(clust);
    }
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
