#include "matrix.h"

Matrix::Matrix() {
    std::vector<Point> empty;
    this->rowCount = 0;
    this->colCount = 0;
    this->matrix = empty;
}

Matrix::Matrix(const std::vector<Point> matrix) {
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
    if (!isMatrix) {
        std::string errMsg = "Cannot have vectors of different dimensions in the same matrix";
        throw std::logic_error(errMsg);
    }
    this->matrix = matrix;
    this->rowCount = dimension;
    this->colCount = matrix.size();
}

Matrix Matrix::GenerateRandomMatrix(const int row, const int col) {
    // rows = dimensions
    // cols = number of points
    std::vector<Point> cols;
    Point p;
    for (int i = 0; i < col; i++) {
        p = p.RandomPoint(row);
        cols.push_back(p);
    }
    Matrix matrix(cols);
    return matrix;
}

/**
 * Generate k random centroids
 */
std::vector<Point> Matrix::RandomCentroids(const int k) const {
    std::vector<Point> centroids(k);
    // place k centroids
    Point p;
    for (int i = 0; i < k; i++) {
        // randomly generate points (make sure same dimensions as matrix)
        centroids.at(i) = p.RandomPoint(this->rowCount);
    }
    return centroids;
} 

/**
 * Group Points into clusters based off centroids
 */ 
Clusters Matrix::ClusterPoints(const int k, const std::vector<Point>& centroids) const {
    Clusters clust(k);
    // initialize each cluster with empty list
    for (int i = 0; i < k; i++) {
        std::vector<Point> cluster;
        clust.at(i) = cluster;
    } 

    // Clusters c, centroids
    for (int i = 0; i < this->matrix.size(); i++) {
        Point p = this->matrix.at(i);
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

/**
 * Calculate new centroids, based on average of clusters
 * return reference?
 */
std::vector<Point> Matrix::AverageClusters(const int k, 
                                           const Clusters& clust, 
                                           const std::vector<Point>& centroids) const {
    std::vector<Point> newCentroids(k);
    for (int i = 0; i < k; i++) {
        std::vector<Point> cluster = clust.at(i);
        if (cluster.size() != 0) {
            int dimension = cluster.at(0).GetDimension();
            Point sum(dimension); // since we can only add Points of same dimension
            for (int j = 0; j < cluster.size() - 1; j++) {
                Point current = cluster.at(j);
                sum = sum + current;
            }
            Point average = sum.Shrink(cluster.size());
            // Replace new averaged centroid
            newCentroids.at(i) = average;
        } else {
            // we just use the old centroid
            newCentroids.at(i) = centroids.at(i);
        }
    }
    return newCentroids;
}

/**
 * Classify point with specific cluster
 * returns index of cluster point is classified as. (-1 returned if error)
 */
int Matrix::ClassifyPoint(const Point& p, const Clusters& clust) const {
    // consider p != clusters dimension
    if (p.GetDimension() == 0)
        return -1;
    
    const int k = clust.size();
    std::vector<Point> centroids = RandomCentroids(k);
    centroids = AverageClusters(k, clust, centroids); 

    if (p.GetDimension() != centroids.at(0).GetDimension())
        return -1;

    int minDistance = std::numeric_limits<int>::max();
    int minCentroidIndex = -1;
    for (int i = 0; i < k; i++) {
        Point currentCentroid = centroids.at(i);
        int dist = p.Distance(currentCentroid);
        if (dist < minDistance) {
            minDistance = dist;
            minCentroidIndex = i;
        }
    }
    return minCentroidIndex;
}

// I think I may refactor this and make it part of Matrix
// Also our KMeans function does more than just classify 
// Since it also prints the clusters, I think this should be a seperate
// optional public function.
void PrintClusters(const Clusters& c, const std::vector<Point>& centroids) {
    for (int i = 0; i < c.size(); i++) {
        std::cout << "Cluster " << i << ": " << "(Centroid = " 
                  << centroids.at(i).ToString() << ")" << std::endl;
        for (int j = 0; j < c.at(i).size(); j++) {
            std::vector<Point> cluster = c.at(i);
            Point p = cluster.at(j);
            std::cout << "Point: " << j << " - "
                      << p.ToString() << std::endl;
        }
        std::cout << std::endl;
    }
}

// O(tkpd)
Clusters Matrix::KMeansClustering(const int k, const int limit) const {
    std::vector<Point> centroids = RandomCentroids(k);
    Clusters clust;

    int iterations = 0;
    while(iterations < limit) {
        clust = ClusterPoints(k, centroids);
        centroids = AverageClusters(k, clust, centroids); // for each cluster we find new centroids
        iterations++;
        std::cout << std::endl << "Iteration " << iterations << ": " << std::endl;
        PrintClusters(clust, centroids);
    }
    return clust;
}

std::vector<Point> Matrix::GetMatrix() const {
    return this->matrix;
}

int Matrix::GetRowCount() const {
    return this->rowCount;
}

int Matrix::GetColCount() const {
    return this->colCount;
}

Point Matrix::GetCol(const int index) const {
    if (index >= this->GetColCount() || index < 0) {
        std::string errMsg = "GetCol() index out of bounds";
        throw std::out_of_range(errMsg);
    }
    return this->matrix.at(index);
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
