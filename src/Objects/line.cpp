#include "line.h"
namespace def = Default;
namespace defline = Default::line;
using obj = GraphicsObject;

//constructor
line::line() : GraphicsObject(), x1(defline::x1), y1(defline::y1), x2(defline::x2), y2(defline::y2) {};
//note line donot have fill property
line::line(const float x1, const float y1, const float x2, const float y2, const std::string& stroke, const float sw) 
           : GraphicsObject(stroke, "none", sw), x1(x1), y1(y1), x2(x2), y2(y2) {};

//destructor
line::~line() {};

//print properties
void line::print_properties() const {
    std::cout << x1 << " " << y1 << " " << x2 << " " << y2 << " ";
    GraphicsObject::print_properties();
}

//setter
void line::set_x1(const float x1){this->x1 = x1;}
void line::set_y1(const float y1){this->y1 = y1;}
void line::set_x2(const float x2){this->x2 = x2;}
void line::set_y2(const float y2){this->y2 = y2;}

//to svg return the svg syntax for line
std::string line::to_svg() const {
    std::string str = "<line ";;
    if (x1 != defline::x1){
        str += "x1=\"" +  std::to_string(x1) + "\" ";
    }   
    if (y1 != defline::y1){
        str += "y1=\"" +  std::to_string(y1) + "\" ";
    }
    if (x2 != defline::x2){
        str += "x2=\"" +  std::to_string(x2) + "\" ";
    }
    if (y2 != defline::y2){
        str += "y2=\"" +  std::to_string(y2) + "\" ";
    }
    if (obj::get_stroke() != def::stroke){
        str += "stroke=\"" + obj::get_stroke() + "\" ";
    }
    if (obj::get_strokewidth() != def::strokewidth){
        str += "stroke-width=\"" + std::to_string(obj::get_strokewidth()) + "\" ";
    }
    str += "/>";
    return str;
}

// int main(){
//     line defuaktline;
//     line lin(0.0,0.0,50.0,100.0,"red",2.0);
//     defuaktline.print_properties();
//     lin.print_properties();
//     std::cout << defuaktline.to_svg() << std::endl;
//     std::cout << lin.to_svg() << std::endl;
//     return 0;
// }