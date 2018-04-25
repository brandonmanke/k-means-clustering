CC = g++
GFLAG = -g
CFLAG = -c
C11FLAG = -std=c++11
DOC = docker
APP = k-means-clustering

default: main.o point.o matrix.o
	$(CC) build/main.o build/point.o build/matrix.o -o bin/out

main.o: src/main.cc
	$(CC) $(CFLAG) $(C11FLAG) src/main.cc -o build/main.o

point.o: src/point.cc
	$(CC) $(CFLAG) $(C11FLAG) src/point.cc -o build/point.o

matrix.o: src/matrix.cc
	$(CC) $(CFLAG) $(C11FLAG) src/matrix.cc -o build/matrix.o

# Unit Tests
test: point_test.o
	$(CC) build/point_test.o -o bin/test_out

point_test.o: test/point_test.cc
	$(CC) $(CFLAG) $(C11FLAG) test/point_test.cc -o build/point_test.o

# Clean
clean:
	rm build/*.o bin/out

# Docker related builds (use these if you are unsure about compiler compatibility)
docker-build:
	$(DOC) build -t $(APP) .

docker-run:
	$(DOC) run -it --rm $(APP)
