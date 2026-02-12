#pragma once
#include "GraphicsObject.h"

class Line : public GraphicsObject {
private:
    float x1,y1,x2,y2;

public:
    //constructor
    Line();
    //note Line donot have fill property
    Line(const float x1, const float y1, const float x2, const float y2, const std::string& stroke=Default::stroke,const float sw = Default::strokewidth);

    //destructor
    ~Line() override;

    //print properties
    void print_properties() const override;

    //setter
    void set_x1(const float x1);
    void set_y1(const float y1);
    void set_x2(const float x2);
    void set_y2(const float y2);
    
    //to svg    
    std::string to_svg() const override;

    //draw Line
    void draw(QPainter& painter) const override;
    //update width and height while forming
    void update_drag(const QPoint& start, const QPoint& end) override;
    //bounding Line
    QRect bounding_rect() const override;
    //inside of Line
    bool inside(const QPoint& point) const override;
    //move Line
    void move(const float del_x, const float del_y) override;
    //cloning Line
    GraphicsObject* clone() const override {return new Line(*this);}
    GraphicsObject* clone(const float x, const float y) const override;
    //get set geom
    Geometry get_geometry() const override;
    void set_geometry(const Geometry& g) override;
};