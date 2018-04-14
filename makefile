CC = g++
GFLAG = -g
CFLAG = -c

default: main.o point2d.o point3d.o
	$(CC) build/main.o build/point2d.o build/point3d.o -o bin/out

main.o: src/main.cc
	$(CC) $(CFLAG) src/main.cc -o build/main.o

point2d.o: src/point2d.cc
	$(CC) $(CFLAG) src/point2d.cc -o build/point2d.o

point3d.o: src/point3d.cc
	$(CC) $(CFLAG) src/point3d.cc -o build/point3d.o

clean:
	rm build/*.o bin/out

