CC=g++
CFLAGS=-std=c++17 -O2 -Wall -pedantic -lpthread -lstdc++fs

chLP: chLP.cpp
	$(CC) -o chLP chLP.cpp $(CFLAGS)
