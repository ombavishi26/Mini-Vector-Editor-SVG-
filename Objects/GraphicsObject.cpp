#include "GraphicsObject.h"

using obj = GraphicsObject;

//Constructor
obj::GraphicsObject(const std::string& strokeColor, const std::string& fillColor, float sw)
    : stroke(strokeColor), fill(fillColor), strokeWidth(sw) {}
obj::GraphicsObject() : stroke("black"), fill("none"), strokeWidth(1.0f) {}

// Destructor
obj::~GraphicsObject() {}

//print properties
void obj::printProperties() const {
    std::cout << stroke << " " << fill << " " << strokeWidth << std::endl;
}
