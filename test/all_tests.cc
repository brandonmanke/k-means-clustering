// https://github.com/google/googletest
#include <gtest/gtest.h>

int main(int argc, char* argv[]) {
    std::cout << "Starting Tests..." << std::endl;
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
