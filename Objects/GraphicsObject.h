#pragma once
#include <iostream>
#include <string>   
#include "config/Default.h"

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
    ~GraphicsObject();
    // Print properties
    void print_properties() const;
    //getter
    std::string get_stroke() const;
    std::string get_fill() const;
    float get_strokewidth() const;
    //setter
    void set_stroke(const std::string stroke);
    void set_fill(const std::string fill);
    void set_sw(const float sw);
    //to svg
    virtual std::string to_svg() const;
};