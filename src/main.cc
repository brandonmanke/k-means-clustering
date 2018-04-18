/**
 * K Means Clustering implementation in C++
 * TODO:
 * Implement loss function
 * Unit Testing
 */
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "point.h"
#include "matrix.h"

int main(void) {
    std::srand(std::time(NULL));
    Matrix::Matrix m;
    m = m.GenerateRandomMatrix(3, 30);
    std::vector<int> v = { 1, 2, 3 };
    std::vector<int> v2 = { 2, 3, 0 };
    Point::Point p(v);
    Point::Point p2(v2);
    std::cout << "Point p: " << p.ToString() << std::endl;
    std::cout << "Point p2: " << p2.ToString() << std::endl << std::endl;
    Point::Point sum = p + p2;
    std::cout << "p + p2: " << sum.ToString() << std::endl << std::endl;
    std::cout << m.ToString() << std::endl;
    
    Clusters c = m.KMeansClustering(5, 8);
    return 0;
}
