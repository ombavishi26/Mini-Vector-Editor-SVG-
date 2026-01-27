#include "GraphicsObject.h"
namespace def = Default;
namespace defcircle = Default::circle;

class circle : public GraphicsObject {
private:
    float r,cx,cy;

public:
    //constructor
    circle();
    circle(const float r, const float cx, const float cy, const std::string& stroke = def::stroke, const std::string& fill = def::fill, const float sw = def::strokewidth);
    //destructor
    ~circle();
    //print properties
    void print_properties() const;
    //to svg
    std::string to_svg() const override;
};