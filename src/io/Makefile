OBJS = ../Objects/GraphicsObject.o ../Objects/rect.o ../Objects/circle.o ../Objects/line.o ../Objects/path.o ../Objects/text.o
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra

check : ParserSvg.o $(OBJS)
	$(CXX) ParserSvg.o $(OBJS) -o ParserSvg

out : SvgSaver.o $(OBJS)
	$(CXX) SvgSaver.o $(OBJS) -o SvgSaver

SvgSaver.o : SvgSaver.cpp
	g++ -c SvgSaver.cpp 

ParserSvg.o : ParserSvg.cpp
	g++ -c ParserSvg.cpp

clean : 
	rm -f SvgSaver.o SvgSaver output.svg