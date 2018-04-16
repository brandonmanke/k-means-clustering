/**
 * K Means Clustering implementation in C++
 * 
 * Consider making Point2D and Point3D into one combined class for N-Dimensional Points
 */
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "point.h"
#include "matrix.h"

int main(void) {
    std::srand(std::time(NULL));
    Matrix::Matrix m;
    m = m.GenerateRandomMatrix(4, 5);
    std::vector<int> v = { 1, 2, 3 };
    Point::Point p(v);
    std::cout << p.ToString() << std::endl << std::endl;
    std::cout << m.ToString() << std::endl;
    //Clusters c = m.KMeansClustering(2);
    /*for (int i = 0; i < c.size(); i++) {
        std::cout << "Cluster " << i << ": " << std::endl;
        for (int j = 0; j < c.at(i).size(); j++) {
            Point::Point p = c.at(i).at(j);
            std::cout << "Point: " << j << std::endl
                      << p.ToString() << std::endl;
        }
    }*/
    return 0;
}
