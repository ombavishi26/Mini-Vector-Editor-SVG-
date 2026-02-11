#pragma once
#include <iostream>
#include <string>   
#include "config/Default.h"
#include <QPainter>

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
    virtual GraphicsObject* clone() const{return new GraphicsObject(*this);};
    virtual GraphicsObject* clone(const float new_x, const float new_y) const{return new GraphicsObject(*this);}
};