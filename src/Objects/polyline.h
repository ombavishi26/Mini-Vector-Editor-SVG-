#pragma once
#include "GraphicsObject.h"

class Polyline : public GraphicsObject {
private:
    std::vector<std::pair<float,float>> points;

public:
    //constructor
    Polyline();
    Polyline(const std::vector<std::pair<float,float>>& points, const std::string& stroke = Default::stroke, const std::string& fill = Default::fill, const float sw = Default::strokewidth);

    //destructor
    ~Polyline() override;

    //print properties
    void print_properties() const override;
    
    //setter 
    void set_points(const std::vector<std::pair<float,float>>& pts);
    void add_point(const float x,const float y);
    
    //to svg
    std::string to_svg() const override;

    //draw Polyline
    void draw(QPainter& painter) const override;
    //update width and height while forming
    void update_drag(const QPoint& start, const QPoint& end) override;
    //bounding polyline
    QRect bounding_rect() const override;
    //inside of polyline
    bool inside(const QPoint& point) const override;
    //move polyline
    void move(const float del_x, const float del_y) override;
    //cloning polyline
    GraphicsObject* clone() const override {return new Polyline(*this);}
    GraphicsObject* clone(const float x, const float y) const override;
    //get set geom
    Geometry get_geometry() const override;
    void set_geometry(const Geometry& g) override;
};