#include "rect.h"

rect::rect() : GraphicsObject(),width(10.0f), height(10.0f), x(0.0f), y(0.0f), rx(0.0f), ry(0.0f) {};
rect::rect(const float w, const float h, const float x, const float y, const float rx, const float ry,
           const std::string& strokeColor, const std::string& fillColor, const float sw) 
           : GraphicsObject(strokeColor, fillColor, sw), width(w), height(h), x(x), y(y), rx(rx), ry(ry) {};
//destructor
rect::~rect() {};
//print properties
void rect::print_properties() const{
    std::cout << width << " " << height << " " << x << " " << y << " " << rx << " " << ry << " " ;
    GraphicsObject::print_properties();   
}
int main (){
    rect defrect;
    rect rec(12,11,2,3,4,5,"red","orange");
    defrect.print_properties();
    rec.print_properties();
    return 0;
}

// <svg width="200" height="200" xmlns="http://www.w3.org/2000/svg">

//   <circle cx="50" cy="100" r="30" stroke="red" stroke-width="2" fill="none"/>

//   <circle cx="130" cy="100" r="30" stroke="blue" stroke-width="2" fill="yellow"/>

// </svg>
