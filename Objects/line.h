#pragma once
#include "GraphicsObject.h"

class line : public GraphicsObject {
private:
    float x1,y1,x2,y2;

public:
    //constructor
    line();
    //note line donot have fill property
    line(const float x1, const float y1, const float x2, const float y2, const std::string& stroke=Default::stroke,const float sw = Default::strokewidth);

    //destructor
    ~line();

    //print properties
    void print_properties() const;

    //setter
    void set_x1(const float x1);
    void set_y1(const float y1);
    void set_x2(const float x2);
    void set_y2(const float y2);
    
    //to svg    
    std::string to_svg() const override;
};