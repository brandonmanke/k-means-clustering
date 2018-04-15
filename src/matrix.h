#ifndef MATRIX_H
#define MATRIX_H

#include <vector>

// Do I even need a matrix? I am pretty sure I dont lmfao
class Matrix {
public:
    Matrix(int rowCount, int colCount);
    Matrix(std::vector<int> vec);
    Matrix(std::vector<int> rows, std::vector<int> cols);
    ~Matrix();
private:
    int rowCount;
    int colCount;
    std::vector<int> rows;
    std::vector<int> cols;
};

#endif
