#include "point.h"

Point::Point(const std::vector<int>& vec) {
    /*for (int i = 0; i < vec.size(); i++) {
        std::cout << "Test" << std::endl;
        this->vec.push_back(vec.at(i));
    }*/
    this->vec = vec;
    this->dimension = vec.size();
}

Point::Point(const int x, const int y) {
    std::vector<int> v;
    v.push_back(x);
    v.push_back(y);
    this->vec = v;
    this->dimension = vec.size();
}

Point::Point(const int x, const int y, const int z) {
    std::vector<int> v;
    v.push_back(x);
    v.push_back(y);
    v.push_back(z);
    this->vec = v;
    this->dimension = vec.size();
}

//Point::~Point() { }

Point Point::Sum(const Point::Point& point) const {
    if (this->dimension != point.dimension) {
        std::cerr << "Cannot sum vectors of different dimensions" << std::endl;
        throw std::exception();
    }
    std::vector<int> newVec;
    for (int i = 0; i < this->dimension; i++) {
        int sum = this->vec.at(i) + point.vec.at(i);
        newVec.push_back(sum);
    }
    Point p(newVec);
    return p;
}

// Euclidean distance
int Point::Distance(const Point::Point& point) const {
    if (this->dimension != point.dimension) {
        std::cerr << "Cannot calculate distance of vectors of different dimensions" << std::endl;
        throw std::exception();
    }
    int dist = 0;
    for (int i = 0; i < this->dimension; i++) {
        int base = this->vec.at(i) - point.vec.at(i);
        dist += pow(base, 2); // (p-q)^2
    }
    return dist;
}

// add set vec?
std::vector<int> Point::GetVector() const {
    return this->vec;
}

int Point::GetIndex(const int index) const {
    if (dimension > index && index >= 0) {
        return this->vec.at(index);
    }
    std::cerr << "GetIndex() index out of bounds" << std::endl;
    throw std::exception();
}

// probably doesnt work
int Point::SetIndex(const int index, const int val) {
    int oldVal = this->vec.at(index);
    this->vec.at(index) = val;
    return oldVal;
}

int Point::GetDimension() const {
    return this->dimension;
}
