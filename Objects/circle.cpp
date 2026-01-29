#include "circle.h"
namespace def = Default;
namespace defcircle = Default::circle;
using obj = GraphicsObject;

//constructor
circle::circle() : GraphicsObject(), r(defcircle::r), cx(defcircle::cx), cy(defcircle::cy) {};
circle::circle(const float r, const float cx, const float cy, const std::string& stroke, const std::string& fill, const float sw) 
           : GraphicsObject(stroke, fill, sw), r(r), cx(cx), cy(cy) {};

//destructor
circle::~circle() {};

//print properties
void circle::print_properties() const {
    std::cout << r << " " << cx << " " << cy << " ";
    GraphicsObject::print_properties();
}

//setter
void circle::set_r(const float r){this->r = r;}
void circle::set_cx(const float cx){this->cx = cx;}
void circle::set_cy(const float cy){this->cy = cy;}

//to svg return the svg syntax for circle
std::string circle::to_svg() const{
    std::string str = "<circle ";
    if (r != defcircle::r){
        str += "r=\"" +  std::to_string(r) + "\" ";
    }
    if (cx != defcircle::cx){
        str += "cx=\"" +  std::to_string(cx) + "\" ";
    }
    if (cy != defcircle::cy){
        str += "cy=\"" +  std::to_string(cy) + "\" ";
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

// int main(){
//     circle defuaktcircle;
//     circle cir(15.0,50.0,100.0,"red","none",2.0);
//     defuaktcircle.print_properties();
//     cir.print_properties();
//     std::cout << defuaktcircle.to_svg() << std::endl;
//     std::cout << cir.to_svg() << std::endl;
//     GraphicsObject* p = &cir;
//     p->print_properties();
//     return 0;
// }