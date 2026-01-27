#pragma once
#include "GraphicsObject.h"
// namespace def = Default;
// namespace defcircle = Default::circle;

class circle : public GraphicsObject {
private:
    float r,cx,cy;

public:
    //constructor
    circle();
    circle(const float r, const float cx, const float cy, const std::string& stroke = Default::stroke, const std::string& fill = Default::fill, const float sw = Default::strokewidth);
    //destructor
    ~circle();
    //print properties
    void print_properties() const;
    //to svg
    std::string to_svg() const override;
};