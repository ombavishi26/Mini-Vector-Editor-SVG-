#include "GraphicsObject.h"

using obj = GraphicsObject;

//Constructor
obj::GraphicsObject(const std::string& strokeColor, const std::string& fillColor, float sw)
    : stroke(strokeColor), fill(fillColor), strokewidth(sw) {}
obj::GraphicsObject() : stroke("black"), fill("none"), strokewidth(1.0f) {}

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
// int main() {
//     GraphicsObject defaultObj;
//     defaultObj.printProperties(); // Should print: black none 1

//     GraphicsObject customObj("red", "blue", 2.5f);
//     customObj.printProperties(); // Should print: red blue 2.5

//     return 0;
// }