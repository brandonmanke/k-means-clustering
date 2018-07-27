// https://github.com/google/googletest
#include <gtest/gtest.h>
#include "../src/point.h"

TEST(PointTest, NoArgConstructorTest) {
    Point p;
    ASSERT_EQ(p.GetDimension(), 0);
    ASSERT_EQ(p.GetVector().empty(), true);
}

TEST(PointTest, ConstructorDimensionArgTest) {
    int dimension = 2;
    Point p(dimension);
    ASSERT_EQ(p.GetDimension(), 2);
    ASSERT_EQ(p.GetVector().size(), 2);
}

TEST(PointTest, ConstructorVectorArgTest) {
    std::vector<int> v { 1, 2, 3 };
    std::vector<int> v2 { 1, 2, 3 };
    Point p(v);
    ASSERT_EQ(p.GetDimension(), 3);
    ASSERT_EQ(p.GetVector(), v2);
}

TEST(PointTest, ConstructorXYArgsTest) {
    int x = 4;
    int y = 3;
    std::vector<int> v { 4, 3 };
    Point p(x, y);
    ASSERT_EQ(p.GetDimension(), 2);
    ASSERT_EQ(p.GetVector(), v);
    ASSERT_EQ(p.GetIndex(0), x);
    ASSERT_EQ(p.GetIndex(1), y);
}

TEST(PointTest, ConstructorXYZArgsTest) {
    int x = 7;
    int y = 8;
    int z = 9;
    std::vector<int> v { 7, 8, 9 };
    Point p(x, y, z);
    ASSERT_EQ(p.GetDimension(), 3);
    ASSERT_EQ(p.GetVector(), v);
    ASSERT_EQ(p.GetIndex(0), x);
    ASSERT_EQ(p.GetIndex(1), y);
    ASSERT_EQ(p.GetIndex(2), z);
}
