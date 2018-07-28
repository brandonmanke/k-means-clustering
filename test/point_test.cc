#include <gtest/gtest.h>
#include "../src/point.h"

TEST(PointTest, NoArgConstructorTest) {
    Point p;
    ASSERT_EQ(p.GetDimension(), 0);
    ASSERT_TRUE(p.GetVector().empty());
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
    Point p(x, y, z);
    std::vector<int> v { 7, 8, 9 };
    ASSERT_EQ(p.GetDimension(), 3);
    ASSERT_EQ(p.GetVector(), v);
    ASSERT_EQ(p.GetIndex(0), x);
    ASSERT_EQ(p.GetIndex(1), y);
    ASSERT_EQ(p.GetIndex(2), z);
}

TEST(PointTest, AdditionOperatorTest) {
    Point p1(1, 2, 3);
    Point p2(3, 2, 1);
    Point result = p1 + p2;
    std::vector<int> v { 4, 4, 4 };
    ASSERT_EQ(result.GetDimension(), 3);
    ASSERT_EQ(result.GetVector(), v);
}

TEST(PointTest, AdditionOperatorExceptionTest) {
    Point p1(2, 2);
    Point p2(4, 7, 9);
    ASSERT_ANY_THROW(p1 + p2);
}

TEST(PointTest, ScalarTest) {
    Point p1(3, 6, 9);
    Point scaled = p1.Scale(2);
    std::vector<int> v { 6, 12, 18 };
    ASSERT_EQ(scaled.GetVector(), v);
}

TEST(PointTest, ShrinkTest) {
    Point p1(6, 12, 18);
    Point scaled = p1.Shrink(2);
    std::vector<int> v { 3, 6, 9 };
    ASSERT_EQ(scaled.GetVector(), v);
}

TEST(PointTest, DistanceTest) {
    Point p1(2, 4);
    Point p2(3, 1);
    int dist = p1.Distance(p2);
    ASSERT_EQ(dist, 10);
}

TEST(PointTest, DistanceExceptionTest) {
    Point p1(1, 2);
    Point p2(3, 4, 5);
    ASSERT_ANY_THROW(p1.Distance(p2));
}

// Not sure how necessary this is
TEST(PointTest, GetVectorTest) {
    std::vector<int> v { 2, 3 };
    Point p(v);
    ASSERT_EQ(p.GetVector(), v);
}

TEST(PointTest, GetIndexTest) {
    std::vector<int> v { 1, 2 };
    Point p(v);
    ASSERT_EQ(p.GetIndex(0), 1);
    ASSERT_EQ(p.GetIndex(1), 2);
    ASSERT_ANY_THROW(p.GetIndex(-1));
    ASSERT_ANY_THROW(p.GetIndex(3));
}

TEST(PointTest, SetIndexTest) {
    std::vector<int> v { 1, 2 };
    Point p(v);
    p.SetIndex(0, 2);
    ASSERT_EQ(p.GetIndex(0), 2);
    p.SetIndex(1, 3);
    ASSERT_EQ(p.GetIndex(1), 3);
    ASSERT_ANY_THROW(p.SetIndex(-1, 5));
    ASSERT_ANY_THROW(p.SetIndex(4, 0));
}

TEST(PointTest, GetDimensionTest) {
    Point p(4);
    ASSERT_EQ(p.GetDimension(), 4);
}

TEST(PointTest, ToStringTest) {
    Point p(1, 2, 3);
    std::string got = p.ToString();
    std::string want = "[ 1, 2, 3 ]";
    ASSERT_EQ(got, want);
}

TEST(PointTest, RandomPointTest) {
    Point p;
    p = p.RandomPoint(2);
    ASSERT_EQ(p.GetDimension(), 2);
}
