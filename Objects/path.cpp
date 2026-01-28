#include "path.h"
namespace def = Default;
namespace defpath = Default::path;
using obj = GraphicsObject;

//constructor
path::path() : GraphicsObject(), d(defpath::d) {};
path::path(const std::string& d, const std::string& stroke, const std::string& fill, const float sw) 
           : GraphicsObject(stroke, fill, sw), d(d) {};

//destructor
path::~path() {};

//print properties
void path::print_properties() const {
    std::cout << d << " ";
    GraphicsObject::print_properties();   
}

//setter
void path::set_d(const std::string& d){this->d = d;}

//to svg return the svg syntax for path
std::string path::to_svg() const {
    std::string str = "<path ";;
    if (d != defpath::d){
        str += "d=\"" +  d + "\" ";
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
//     path defuaktpath;
//     path pa("M10 10 H 90 V 90 H 10 L 10 10","red","blue",2.0);
//     defuaktpath.print_properties();
//     pa.print_properties();
//     std::cout << defuaktpath.to_svg() << std::endl;
//     std::cout << pa.to_svg() << std::endl;
//     return 0;
// }