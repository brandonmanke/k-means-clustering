// https://github.com/google/googletest
#include <iostream>
#include <gtest/gtest.h>

TEST(HelloWorldTest, AssertTrueEqTrue) {
    ASSERT_EQ(true, true);
}

int main(int argc, char* argv[]) {
    std::cout << "Starting Tests..." << std::endl;
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
