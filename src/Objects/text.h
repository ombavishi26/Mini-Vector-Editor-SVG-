#pragma once
#include "GraphicsObject.h"

class text : public GraphicsObject {
private:
    float x,y,dx,dy,rotate;
    int font_size;
    std::string content;    

public:
    //constructor 
    text();
    text(const float x,const float y,const float dx,const float dy,const float rotate, const int font_size, const std::string& content,const std::string& stroke,const std::string& fill, const float sw);

    //destructor
    ~text() override;

    //print properties
    void print_properties() const override;

    //setter
    void set_x(const float x);
    void set_y(const float y);
    void set_dx(const float dx);
    void set_dy(const float dy);
    void set_rotate(const float rotate);
    void set_font_size(const int font_size);
    void set_content(const std::string& content);
    
    //to _svg return  a string in svg formate
    std::string to_svg() const override;
};