#include "GraphicsObject.h"

class rect : public GraphicsObject {
private:
    float width,height,x,y,rx,ry;

public:
    //constructor
    rect();
    rect(const float w, const float h, const float x, const float y, const float rx, const float ry,
         const std::string& strokeColor="black", const std::string& fillColor="none", const float sw=1.0);
    //destructor
    ~rect();
    //print properties
    void print_properties() const;
    //to svg
    std::string to_svg() const;
};