#pragma once
#include <iostream>
#include <string>   
#include "config/Default.h"
#include <QPainter>

enum HandleType {None_handle, TopLeft, TopRight, BottomLeft, BottomRight};
struct Geometry {
    float x, y, width, height;
};

class GraphicsObject {
private:
    std::string stroke;
    std::string fill;
    float strokewidth;

public:
    // Constructor
    GraphicsObject();
    GraphicsObject(const std::string& strokeColor, const std::string& fillColor, float sw);
    // Destructor
    virtual~GraphicsObject();
    // Print properties
    virtual void print_properties() const;
    //getter
    std::string get_stroke() const;
    std::string get_fill() const;
    float get_strokewidth() const;
    //setter
    void set_stroke(const std::string& stroke);
    void set_fill(const std::string& fill);
    void set_sw(const float sw);
    //to svg
    virtual std::string to_svg() const;
    //draw objects
    virtual void draw(QPainter& painter) const {};
    //changing properties when object is drag while forming
    virtual void update_drag(const QPoint& start, const QPoint& end) {};
    //moving objects
    virtual void move(const QPoint& delta) {};
    //checking if point is inside 
    virtual bool inside(const QPoint& point) const ;
    //bounding rect
    virtual QRect bounding_rect() const;
    //move object
    virtual void move(const float del_x, const float del_y) {};
    //cloning object
    virtual GraphicsObject* clone() const {};
    virtual GraphicsObject* clone(const float new_x, const float new_y) const {};
    //get and set geometry
    virtual Geometry get_geometry() const {};
    virtual void set_geometry(const Geometry& g) {};
    //getting point on bounding rect
    virtual HandleType hitHandle(const QPoint& p) const;
    virtual bool supportResize() const {return true;}
};