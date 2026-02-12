#pragma once
#include "GraphicsObject.h"
// namespace def = Default;
// namespace defCircle = Default::Circle;

class Circle : public GraphicsObject {
private:
    float r,cx,cy;

public:
    //constructor
    Circle();
    Circle(const float r, const float cx, const float cy, const std::string& stroke = Default::stroke, const std::string& fill = Default::fill, const float sw = Default::strokewidth);

    //destructor
    ~Circle() override;

    //print properties
    void print_properties() const override;
    
    //setter 
    void set_r(const float r);
    void set_cx(const float cx);
    void set_cy(const float cy);
    
    //to svg
    std::string to_svg() const override;

    //draw Circle
    void draw(QPainter& painter) const override;
    //update width and height while forming
    void update_drag(const QPoint& start, const QPoint& end) override;
    //bounding circle
    QRect bounding_rect() const override;
    //inside of circle
    bool inside(const QPoint& point) const override;
    //move circle
    void move(const float del_x, const float del_y) override;
    //cloning circle
    GraphicsObject* clone() const override {return new Circle(*this);}
    GraphicsObject* clone(const float x, const float y) const override;
    //get set geom
    Geometry get_geometry() const override;
    void set_geometry(const Geometry& g) override;
};