#include "GraphicsObject.h"

using obj = GraphicsObject;
// using namespace a = Default;;

//Constructor
obj::GraphicsObject(const std::string& strokeColor, const std::string& fillColor, float sw)
    : stroke(strokeColor), fill(fillColor), strokewidth(sw) {}
obj::GraphicsObject() : stroke(Default::stroke), fill(Default::fill), strokewidth(Default::strokewidth) {}

// Destructor
obj::~GraphicsObject() {}

//print properties
void obj::print_properties() const {
    std::cout << stroke << " " << fill << " " << strokewidth << std::endl; 
}

//getter
std::string obj::get_stroke() {return stroke;}
std::string obj::get_fill() {return fill;}
float obj::get_strokewidth () {return strokewidth;}

//to svg
std::string obj::to_svg() const {return "we are in Graphicsobject";};

// int main() {
//     GraphicsObject defaultObj;
//     defaultObj.printProperties(); // Should print: black none 1

//     GraphicsObject customObj("red", "blue", 2.5f);
//     customObj.printProperties(); // Should print: red blue 2.5

//     return 0;
// }