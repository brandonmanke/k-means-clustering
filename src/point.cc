#include "point.h"

Point::Point() {
    std::vector<int> v;
    this->vec = v;
    this->dimension = 0;
}

/**
 * Initialize a n-dimensional 0 vector
 */ 
Point::Point(const int dimension) {
    this->dimension = dimension;
    std::vector<int> v(this->dimension);
    this->vec = v;
}

Point::Point(const std::vector<int> vec) {
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

//Point Point::Sum(const Point::Point& point) const { }

/**
 * Point / Vector addition
 */
Point Point::operator +(const Point& point) const {
    if (this->dimension != point.dimension) {
        // We could be smart about this and take the bigger
        // dimension and just add 0 to each number outside
        // the dimension of the smaller vector. 
        // return point of bigger dimension
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

/**
 * Scalar multiplication for point/vector
 */
Point Point::Scale(const int scalar) const {
    std::vector<int> newVec(this->dimension);
    for (size_t i = 0; i < newVec.size(); i++) {
        newVec.at(i) = this->vec.at(i) * scalar;
    }
    Point scaledPoint(newVec);
    return scaledPoint;
}

/**
 * Scalar multiplication for values 0 < n < 1
 * This is only because we are using integers for everything.
 */
Point Point::Shrink(const int scalar) const {
    std::vector<int> newVec(this->dimension);
    for (size_t i = 0; i < newVec.size(); i++) {
        newVec.at(i) = this->vec.at(i) / scalar;
    }
    Point scaledPoint(newVec);
    return scaledPoint;
}

/**
 * Euclidean distance
 */
int Point::Distance(const Point& point) const {
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

std::string Point::ToString() const {
    std::stringstream ss;
    ss << "[ ";
    for (size_t i = 0; i < this->vec.size() -1; i++) {
        ss << this->vec.at(i) << ", ";
    }
    ss << this->vec.at(this->vec.size() - 1) << " ]";
    std::string str = ss.str();
    return str;
}

Point Point::RandomPoint(const int dimension) {
    std::vector<int> vec(dimension);
    for (int i = 0; i < dimension; i++) {
        // 0 and 999 for now (because dist gets too big without sqrt)
        // Might consider changing everything to longs or doubles.
        int r = std::rand() % 999; 
        vec.at(i) = r;
    }
    Point p(vec);
    return p;
}
