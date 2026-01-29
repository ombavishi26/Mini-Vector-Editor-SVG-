CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra

OBJS = ../../Objects/GraphicsObject.o ../../Objects/rect.o ../../Objects/circle.o ../../Objects/line.o ../../Objects/path.o ../../Objects/text.o

PAR = ParserSvg.o ParserCircle.o ParserUtils.o ParserRect.o ParserLine.o ParserPath.o ParserText.o

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

ParserLine.o : ParserLine.cpp	
	$(CXX) $(CXXFLAGS) -c ParserLine.cpp

ParserPath.o : ParserPath.cpp	
	$(CXX) $(CXXFLAGS) -c ParserPath.cpp

ParserText.o : ParserText.cpp	
	$(CXX) $(CXXFLAGS) -c ParserText.cpp
	
clean:
	rm -f ParserSvg.o ParserCircle.o ParserUtils.o ParserSvg