#include "GraphicsObject.h"

using obj = GraphicsObject;
// using namespace a = Default;;

//Constructor
obj::GraphicsObject(const std::string& strokeColor, const std::string& fillColor, float sw)
    : stroke(strokeColor), fill(fillColor), strokewidth(sw) {}
obj::GraphicsObject() : stroke(Default::stroke), fill(Default::fill), strokewidth(Default::strokewidth) {}

// Destructor
obj::~GraphicsObject() {}

//print properties
void obj::print_properties() const {
    // std::cout << "DEBUG: About to print stroke" << std::endl;
    std::cout << stroke << " ";
    // std::cout << "DEBUG: About to print fill" << std::endl;
    std::cout << fill << " ";
    // std::cout << "DEBUG: About to print strokewidth" << std::endl;
    std::cout << strokewidth << std::endl;
}

//getter
std::string obj::get_stroke() const {return stroke;}
std::string obj::get_fill() const {return fill;}
float obj::get_strokewidth () const {return strokewidth;}

//setter
void obj::set_stroke(const std::string& stroke){this->stroke = stroke;}
void obj::set_fill(const std::string& fill){this->fill = fill;}
void obj::set_sw(const float sw){obj::strokewidth = sw;}

//checking if point is inside
bool obj::inside(const QPoint& point) const {return bounding_rect().contains(point);}

//bounding rect
QRect obj::bounding_rect() const {return QRect();} 

//to svg
std::string obj::to_svg() const {return "we are in Graphicsobject";};

//getting point for resize
HandleType GraphicsObject::hitHandle(const QPoint& p) const {
    Geometry g = get_geometry();
    const int size = 5;
    QRectF tl(g.x - size, g.y - size, size*2, size*2);
    QRectF tr(g.x + g.width - size, g.y - size, size*2, size*2);
    QRectF bl(g.x - size, g.y + g.height - size, size*2, size*2);
    QRectF br(g.x + g.width - size, g.y + g.height - size, size*2, size*2);

    if (tl.contains(p)) return TopLeft;
    if (tr.contains(p)) return TopRight;
    if (bl.contains(p)) return BottomLeft;
    if (br.contains(p)) return BottomRight;

    return None_handle;
}
// int main() {
//     GraphicsObject defaultObj;
//     defaultObj.set_fill("om");
//     defaultObj.print_properties(); // Should print: black none 1

//     GraphicsObject customObj("red", "blue", 2.5f);
//     customObj.set_sw(93.224);
//     customObj.print_properties(); // Should print: red blue 2.5

//     return 0;
// }