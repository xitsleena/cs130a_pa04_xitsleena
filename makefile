CXX = g++
CXXFLAGS = -Wall -Wno-uninitialized -std=c++11
BINARIES = snl 

all: snl.out 

snl.out: snake.cpp
	$(CXX) $(CXXFLAGS) $^ -o snl

clean:
	/bin/rm -f $(BINARIES) *.o