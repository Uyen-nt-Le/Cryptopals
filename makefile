main: main.o conversion.o utilities.o set1.o
	clang++ main.o conversion.o utilities.o set1.o -o main

main.o: main.cpp
	clang++ -std=c++17 -g -c main.cpp

conversion.o: conversion.cpp conversion.h
	clang++ -std=c++17 -g -c conversion.cpp

utilities.o: utilities.cpp utilities.h
	clang++ -std=c++17 -g -c utilities.cpp

set1.o: set1.cpp set1.h
	clang++ -std=c++17 -g -c set1.cpp

clean:
	rm *.o main