#pragma once
#include "GraphicsObject.h"

class Text : public GraphicsObject {
private:
    float x,y,rotate;
    int font_size;
    std::string content;    

public:
    //constructor 
    Text();
    Text(const float x,const float y,const float rotate,const int font_size,const std::string& content,const std::string& stroke,const std::string& fill, const float sw);

    //destructor
    ~Text() override;

    //print properties
    void print_properties() const override;

    //setter
    void set_x(const float x);
    void set_y(const float y);
    void set_rotate(const float rotate);
    void set_font_size(const int font_size);
    void set_content(const std::string& content);
    
    //to _svg return  a string in svg formate
    std::string to_svg() const override;

    bool supportResize() const override {return false;}

    //draw Text
    void draw(QPainter& painter) const override;
    //update width and height while forming
    // void update_drag(const QPoint& start, const QPoint& end) override;
    //bounding Text
    QRect bounding_rect() const override;
    //inside of Text
    bool inside(const QPoint& point) const override;
    //move Text
    void move(const float del_x, const float del_y) override;
    //cloning Text
    GraphicsObject* clone() const override {return new Text(*this);}
    GraphicsObject* clone(const float x, const float y) const override;
    //get set geom
    Geometry get_geometry() const override;
    void set_geometry(const Geometry& g) override;
};