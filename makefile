CC = g++
GFLAG = -g
CFLAG = -c
C11FLAG = -std=c++11
DOC = docker
APP = k-means-clustering

# GTEST
GTEST_DIR = third_party/googletest-1.8.0/googletest
USER_DIR = src
BUILD_DIR = build
TEST_DIR = test
CPPFLAGS += -isystem $(GTEST_DIR)/include
#-pthread unused
CXXFLAGS += -g -Wall -Wextra -std=c++11
TESTS = point_test
GTEST_HEADERS = $(GTEST_DIR)/include/gtest/*.h \
                $(GTEST_DIR)/include/gtest/internal/*.h
GTEST_SRCS_ = $(GTEST_DIR)/src/*.cc $(GTEST_DIR)/src/*.h $(GTEST_HEADERS)

default: main.o point.o matrix.o
	$(CC) build/main.o build/point.o build/matrix.o -o bin/out

all: $(TESTS)

main.o: src/main.cc
	$(CC) $(CFLAG) $(C11FLAG) src/main.cc -o build/main.o

point.o: $(USER_DIR)/point.cc $(USER_DIR)/point.h $(GTEST_HEADERS)
	$(CC) $(CPPFLAGS) $(CXXFLAGS) -c $(USER_DIR)/point.cc

matrix.o: src/matrix.cc
	$(CC) $(CFLAG) $(C11FLAG) src/matrix.cc -o build/matrix.o

# Unit Tests
#point_test: point_test.o $(USER_DIR)/point.h

point_test.o: $(TEST_DIR)/point_test.cc $(GTEST_HEADERS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(TEST_DIR)/point_test.cc

point_test: point.o point_test.o gtest_main.a
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -lpthread $^ -o $@

# Clean
clean:
	rm build/*.o bin/out
	rm -f $(TESTS) gtest.a gtest_main.a *.o

# Docker related builds (use these if you are unsure about compiler compatibility)
docker-build:
	$(DOC) build -t $(APP) .

docker-run:
	$(DOC) run -it --rm $(APP)

# Google Test

gtest-all.o: $(GTEST_SRCS_)
	$(CXX) $(CPPFLAGS) -I$(GTEST_DIR) $(CXXFLAGS) -c \
            $(GTEST_DIR)/src/gtest-all.cc

gtest_main.o: $(GTEST_SRCS_)
	$(CXX) $(CPPFLAGS) -I$(GTEST_DIR) $(CXXFLAGS) -c \
            $(GTEST_DIR)/src/gtest_main.cc

gtest.a: gtest-all.o
	$(AR) $(ARFLAGS) $@ $^

gtest_main.a: gtest-all.o gtest_main.o
	$(AR) $(ARFLAGS) $@ $^
