/**
 * K Means Clustering implementation in C++
 * TODO:
 * Implement loss function
 * Unit Testing
 * Docker
 */
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "point.h"
#include "matrix.h"

int main(void) {
    std::srand(std::time(NULL));
    Matrix m;
    m = m.GenerateRandomMatrix(3, 30);
    std::vector<int> v = { 1, 2, 3 };
    std::vector<int> v2 = { 2, 3, 0 };
    Point p(v);
    Point p2(v2);
    std::cout << "Point p: " << p.ToString() << std::endl;
    std::cout << "Point p2: " << p2.ToString() << std::endl << std::endl;
    Point sum = p + p2;
    std::cout << "p + p2: " << sum.ToString() << std::endl << std::endl;
    std::cout << m.ToString() << std::endl;
    
    Clusters c = m.KMeansClustering(5, 8);
    p = p.RandomPoint(3);
    std::cout << "Classify p: " << p.ToString() << std::endl
              << "Is closest to cluster: " << m.ClassifyPoint(p, c) << std::endl; 
    return 0;
}
