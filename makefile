start: main.o source.o
	g++ main.o branchslice.o -o gotest

main.o: main.cpp
	g++ -c main.cpp

source.o: branchslice.cpp branchslice.h
	g++ -c branchslice.cpp

go:
	clear
	./gotest
	rm *.o
	rm gotest
	ls
