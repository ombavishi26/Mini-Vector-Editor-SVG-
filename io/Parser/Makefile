CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra

OBJS = ../../Objects/GraphicsObject.o ../../Objects/rect.o ../../Objects/circle.o ../../Objects/line.o ../../Objects/path.o ../../Objects/text.o

PAR = ParserSvg.o ParserCircle.o ParserUtils.o ParserRect.o

check: $(PAR) $(OBJS)
	$(CXX) $(PAR) $(OBJS) -o ParserSvg

ParserSvg.o: ParserSvg.cpp
	$(CXX) $(CXXFLAGS) -c ParserSvg.cpp

ParserCircle.o: ParserCircle.cpp
	$(CXX) $(CXXFLAGS) -c ParserCircle.cpp

ParserUtils.o: ParserUtils.cpp
	$(CXX) $(CXXFLAGS) -c ParserUtils.cpp

ParserRect.o : ParserRect.cpp	
	$(CXX) $(CXXFLAGS) -c ParserRect.cpp

clean:
	rm -f ParserSvg.o ParserCircle.o ParserUtils.o ParserSvg