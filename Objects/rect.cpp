#include "rect.h"
namespace def = Default;
namespace defrect = Default::rect;
using obj = GraphicsObject;

rect::rect() : GraphicsObject(),width(defrect::width), height(defrect::height), x(defrect::x), y(defrect::y), rx(defrect::rx), ry(defrect::ry) {};
rect::rect(const float w, const float h, const float x, const float y, const float rx, const float ry, const std::string& stroke, const std::string& fill, const float sw) 
           : GraphicsObject(stroke, fill, sw), width(w), height(h), x(x), y(y), rx(rx), ry(ry) {};
//destructor
rect::~rect() {};
//print properties
void rect::print_properties() const{
    std::cout << width << " " << height << " " << x << " " << y << " " << rx << " " << ry << " " ;
    GraphicsObject::print_properties();   
}
//to svg return the svg syntax for rect
std::string rect::to_svg() const {
    std::string str ="<rect ";
    if(width != Default::rect::width){
        str += "width=\"" + std::to_string(width) + "\" ";
    }
    if (height != Default::rect::height){
        str += "height=\"" + std::to_string(height) + "\" ";
    }
    if (x != Default::rect::x){
        str += "x=\"" + std::to_string(x) + "\" ";
    }
    if (y != Default::rect::y){
        str += "y=\"" + std::to_string(y) + "\" ";
    }
    if (rx != Default::rect::rx){
        str += "rx=\"" + std::to_string(rx) + "\" ";
    }
    if (ry != Default::rect::ry){
        str += "ry=\"" + std::to_string(ry) + "\" ";
    }  
    if (obj::get_stroke() != def::stroke){
        str += "stroke=\"" + obj::get_stroke() + "\" ";
    }
    if (obj::get_fill() != def::fill){
        str += "fill=\"" + obj::get_fill() + "\" ";
    }
    if (obj::get_strokewidth() != def::strokewidth){
        str += "stroke-width=\"" + std::to_string(obj::get_strokewidth()) + "\" ";
    }
    str += "/>";
    return str;
}

int main (){
    rect defaultrect;
    rect rec(12,11,2,3,4,5,"red","orange");
    defaultrect.print_properties();
    rec.print_properties();
    std::cout << defaultrect.to_svg() << std::endl;
    std::cout << rec.to_svg() << std::endl;
    return 0;
}

// <svg width="200" height="200" xmlns="http://www.w3.org/2000/svg">

//   <circle cx="50" cy="100" r="30" stroke="red" stroke-width="2" fill="none"/>

//   <circle cx="130" cy="100" r="30" stroke="blue" stroke-width="2" fill="yellow"/>

// </svg>
