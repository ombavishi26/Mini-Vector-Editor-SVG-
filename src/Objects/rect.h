#pragma once
#include "GraphicsObject.h"

class Rect : public GraphicsObject {
private:
    float width,height,x,y,rx,ry;

public:
    //constructor
    Rect();
    Rect(const float w, const float h, const float x, const float y, const float rx, const float ry,
         const std::string& stroke=Default::stroke, const std::string& fill=Default::fill, const float sw = Default::strokewidth);
    //destructor
    ~Rect() override;
    //print properties
    void print_properties() const override;
    //setter
    void set_width(const float width);
    void set_height(const float height);
    void set_x(const float x);
    void set_y(const float y);
    void set_rx(const float rx);
    void set_ry(const float ry);
    //getter
    int get_width() const;
    int get_height() const;
    int get_x() const;
    int get_y() const;
    int get_rx() const; 
    int get_ry() const;
    //to svg
    std::string to_svg() const override;
    //draw rect
    void draw(QPainter& painter) const override;
    //update width and height while forming
    void update_drag(const QPoint& start, const QPoint& end) override;
};