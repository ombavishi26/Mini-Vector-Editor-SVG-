#pragma once
#include "GraphicsObject.h"

class path : public GraphicsObject {
private:
    std::string d;

public:
    //constructor
    path();
    path(const std::string& d, const std::string& stroke = Default::stroke, const std::string& fill = Default::fill, const float sw = Default::strokewidth);
    //destructor
    ~path();
    //print properties
    void print_properties() const;
    //to svg    
    std::string to_svg() const override;
};