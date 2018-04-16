CC = g++
GFLAG = -g
CFLAG = -c
C11FLAG = -std=c++11

default: main.o point.o matrix.o
	$(CC) build/main.o build/point.o build/matrix.o -o bin/out

main.o: src/main.cc
	$(CC) $(CFLAG) $(C11FLAG) src/main.cc -o build/main.o

point.o: src/point.cc
	$(CC) $(CFLAG) $(C11FLAG) src/point.cc -o build/point.o

matrix.o: src/matrix.cc
	$(CC) $(CFLAG) $(C11FLAG) src/matrix.cc -o build/matrix.o

clean:
	rm build/*.o bin/out
