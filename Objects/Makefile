CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra 
OBJS = GraphicsObject.o rect.o circle.o line.o path.o text.o

all : main

main : 
	$(CXX) $(OBJS) -o Objects 

GraphicsObject.o : GraphicsObject.cpp
	$(CXX) $(CXXFLAGS) -c GraphicsObject.cpp 

rect.o : rect.cpp
	$(CXX) $(CXXFLAGS) -c rect.cpp

circle.o : circle.cpp
	$(CXX) $(CXXFLAGS) -c circle.cpp

line.o : line.cpp
	$(CXX) $(CXXFLAGS) -c line.cpp

path.o : path.cpp
	$(CXX) $(CXXFLAGS) -c path.cpp

text.o : text.cpp
	$(CXX) $(CXXFLAGS) -c text.cpp

clean :
	rm -f $(OBJS) Objects