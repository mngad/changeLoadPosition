CC=g++
CFLAGS=-std=gnu++0x -O2 -Wall -pedantic -lpthread -lboost_system -lboost_filesystem

chLP: chLP.cpp
	$(CC) -o chLP chLP.cpp $(CFLAGS)
