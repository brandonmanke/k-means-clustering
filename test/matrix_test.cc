#include <gtest/gtest.h>
#include "../src/matrix.h"

TEST(MatrixTest, NoArgsConstructorTest) {
    Matrix m;
    ASSERT_EQ(m.GetRowCount(), 0);
    ASSERT_EQ(m.GetColCount(), 0);
    ASSERT_TRUE(m.GetMatrix().empty());
}

TEST(MatrixTest, ConstructorTest) {
    Point p1(1, 2, 3);
    Point p2(4, 5, 6);
    std::vector<Point> matrix { p1, p2 };
    Matrix m(matrix);
    ASSERT_EQ(m.GetColCount(), 2);
    ASSERT_EQ(m.GetRowCount(), 3);
    ASSERT_EQ(m.GetCol(0).GetVector(), p1.GetVector());
    ASSERT_EQ(m.GetCol(1).GetVector(), p2.GetVector());
}

TEST(MatrixTest, ConstructorExceptionTest) {
    Point p1(1, 2, 3);
    Point p2(4, 5);
    std::vector<Point> matrix { p1, p2 };
    ASSERT_ANY_THROW(Matrix m(matrix));
}

TEST(MatrixTest, RandomMatrixTest) {
    Matrix m;
    m = m.GenerateRandomMatrix(4, 3);
    ASSERT_EQ(m.GetRowCount(), 4);
    ASSERT_EQ(m.GetColCount(), 3);
}

// TODO
//Clusters KMeansClustering(const int k, const int limit) const;
//int ClassifyPoint(const Point& p, const Clusters& clust) const;

TEST(MatrixTest, GetMatrixTest) {
    Point p1(1, -1);
    Point p2(-1, 1);
    std::vector<Point> matrix { p1, p2 };
    Matrix m(matrix);
    Point got1 = m.GetMatrix().at(0);
    Point got2 = m.GetMatrix().at(1);
    ASSERT_EQ(m.GetMatrix().size(), 2);
    ASSERT_EQ(got1.GetIndex(0), 1);
    ASSERT_EQ(got1.GetIndex(1), -1);
    ASSERT_EQ(got2.GetIndex(0), -1);
    ASSERT_EQ(got2.GetIndex(1), 1);
}

TEST(MatrixTest, GetRowCountTest) {
    Point p1(1, 2, 4);
    Point p2(6, 3, 8);
    std::vector<Point> v { p1, p2 };
    Matrix m(v);
    ASSERT_EQ(m.GetRowCount(), 3);
}

TEST(MatrixTest, GetColCountTest) {
    Point p1(1, 2);
    Point p2(7, 8);
    Point p3(4, 4);
    Point p4(3, 9);
    std::vector<Point> v { p1, p2, p3, p4 };
    Matrix m(v);
    ASSERT_EQ(m.GetColCount(), 4);
}

TEST(MatrixTest, GetColTest) {
    Point p1(1, 2);
    Point p2(3, 4);
    std::vector<Point> v { p1, p2 };
    Matrix m(v);
    ASSERT_EQ(m.GetCol(0).GetVector(), p1.GetVector());
    ASSERT_EQ(m.GetCol(1).GetVector(), p2.GetVector());
}

TEST(MatrixTest, GetColExceptionTest) {
    Point p1(1, 2);
    Point p2(4, 3);
    std::vector<Point> v { p1, p2 };
    Matrix m(v);
    ASSERT_ANY_THROW(m.GetCol(-1));
    ASSERT_ANY_THROW(m.GetCol(9));
}

TEST(MatrixTest, ToStringTest) {
    Point p1(1, 2);
    Point p2(3, 4);
    std::vector<Point> v { p1, p2 };
    Matrix m(v);
    std::string actual = m.ToString();
    std::string expected = "[ 1, 2 ]\n[ 3, 4 ]\n";
    ASSERT_EQ(actual, expected);
}
