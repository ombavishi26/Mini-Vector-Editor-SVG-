CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra 

all:
	$(CXX) $(CXXFLAGS) GraphicsObject.cpp $(FILE).cpp -o $(FILE)

run : all
	./$(FILE)

clean:
	rm -f $(FILE)