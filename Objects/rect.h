#pragma once
#include "GraphicsObject.h"

class rect : public GraphicsObject {
private:
    float width,height,x,y,rx,ry;

public:
    //constructor
    rect();
    rect(const float w, const float h, const float x, const float y, const float rx, const float ry,
         const std::string& stroke=Default::stroke, const std::string& fill=Default::fill, const float sw = Default::strokewidth);
    //destructor
    ~rect();
    //print properties
    void print_properties() const;
    //to svg
    std::string to_svg() const override;
};