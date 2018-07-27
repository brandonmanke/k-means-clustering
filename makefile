CC = g++
GFLAG = -g
CFLAG = -c
C11FLAG = -std=c++11
DOC = docker
APP = k-means-clustering
GIT = git

# GTEST
GTEST_DIR = third_party/googletest/googletest
USER_DIR = src
BUILD_DIR = build
TEST_DIR = test
CPPFLAGS += -isystem $(GTEST_DIR)/include
CXXFLAGS += $(GFLAG) -Wall -Wextra -pthread $(C11FLAG)
TESTS = point_test matrix_test all_tests
GTEST_HEADERS = $(GTEST_DIR)/include/gtest/*.h \
                $(GTEST_DIR)/include/gtest/internal/*.h
GTEST_SRCS_ = $(GTEST_DIR)/src/*.cc $(GTEST_DIR)/src/*.h $(GTEST_HEADERS)
MATRIX_TEST_OBJ = $(BUILD_DIR)/matrix.o $(BUILD_DIR)/matrix_test.o $(BUILD_DIR)/gtest_main.a
POINT_TEST_OBJ = $(BUILD_DIR)/point.o $(BUILD_DIR)/point_test.o $(BUILD_DIR)/gtest_main.a

default: main.o point.o matrix.o
	$(CC) $(BUILD_DIR)/main.o $(BUILD_DIR)/point.o $(BUILD_DIR)/matrix.o -o bin/out

install:
	$(GIT) submodule init && $(GIT) submodule update

# matrix_test has linker error
test: all_tests

main.o: src/main.cc
	$(CC) $(CFLAG) $(C11FLAG) src/main.cc -o $(BUILD_DIR)/$@

point.o: $(USER_DIR)/point.cc $(USER_DIR)/point.h $(GTEST_HEADERS)
	$(CC) $(CPPFLAGS) $(CXXFLAGS) -c $(USER_DIR)/point.cc -o $(BUILD_DIR)/$@

matrix.o: $(USER_DIR)/matrix.cc $(USER_DIR)/matrix.h $(GTEST_HEADERS)
	$(CC) $(CFLAG) $(C11FLAG) src/matrix.cc -o $(BUILD_DIR)/$@

# Unit Tests

point_test.o: $(TEST_DIR)/point_test.cc $(GTEST_HEADERS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(TEST_DIR)/point_test.cc -o $(BUILD_DIR)/$@

point_test: point.o point_test.o gtest_main.a
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -lpthread $(POINT_TEST_OBJ) -o bin/$@

matrix_test.o: $(TEST_DIR)/matrix_test.cc $(GTEST_HEADERS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(TEST_DIR)/matrix_test.cc -o $(BUILD_DIR)/$@

matrix_test: matrix.o matrix_test.o gtest_main.a
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -lpthread $(MATRIX_TEST_OBJ) -o bin/$@

all_tests.o: $(TEST_DIR)/all_tests.cc $(GTEST_HEADERS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(TEST_DIR)/all_tests.cc -o $(BUILD_DIR)/$@

# $(MATRIX_TEST_OBJ) & matrix_test broken
all_tests: all_tests.o point_test gtest_main.a
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -lpthread $(POINT_TEST_OBJ) -o bin/$@

# Clean
clean:
	rm -f $(TESTS) $(BUILD_DIR)/*.o $(BUILD_DIR)/*.a bin/*

# Docker related builds (use these if you are unsure about compiler compatibility)
docker-build:
	$(DOC) build -t $(APP) .

docker-run:
	$(DOC) run -it --rm $(APP)

# Google Test

gtest-all.o: $(GTEST_SRCS_)
	$(CXX) $(CPPFLAGS) -I$(GTEST_DIR) $(CXXFLAGS) -c \
            $(GTEST_DIR)/src/gtest-all.cc -o $(BUILD_DIR)/gtest-all.o

gtest_main.o: $(GTEST_SRCS_)
	$(CXX) $(CPPFLAGS) -I$(GTEST_DIR) $(CXXFLAGS) -c \
            $(GTEST_DIR)/src/gtest_main.cc -o $(BUILD_DIR)/gtest_main.o

gtest.a: gtest-all.o
	$(AR) $(ARFLAGS) $(BUILD_DIR)/$@ $(BUILD_DIR)/$^

gtest_main.a: gtest-all.o gtest_main.o
	$(AR) $(ARFLAGS) $(BUILD_DIR)/$@ $(BUILD_DIR)/gtest-all.o $(BUILD_DIR)/gtest_main.o
