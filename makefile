CC = g++
GFLAG = -g
CFLAG = -c

default: main.o
	$(CC) $(GFLAG) build/main.o -o bin/out

main.o: src/main.cc
	$(CC) $(CFLAG) src/main.cc -o build/main.o

clean:
	rm build/*.o && bin/out

