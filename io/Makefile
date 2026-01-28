OBJS = ../Objects/GraphicsObject.o ../Objects/rect.o ../Objects/circle.o ../Objects/line.o ../Objects/path.o ../Objects/text.o

SvgSaver.o : SvgSaver.cpp
	g++ -c SvgSaver.cpp 

all : SvgSaver.o $(OBJS)
	$(CXX) SvgSaver.o $(OBJS) -o SvgSaver

clean : 
	rm -f SvgSaver.o SvgSaver output.svg