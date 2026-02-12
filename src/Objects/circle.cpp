#include "circle.h"
#include <cmath>
namespace def = Default;
namespace defCircle = Default::Circle;
using obj = GraphicsObject;

//constructor
Circle::Circle() : GraphicsObject(), r(defCircle::r), cx(defCircle::cx), cy(defCircle::cy) {};
Circle::Circle(const float r, const float cx, const float cy, const std::string& stroke, const std::string& fill, const float sw) 
           : GraphicsObject(stroke, fill, sw), r(r), cx(cx), cy(cy) {};

//destructor
Circle::~Circle() {};

//print properties
void Circle::print_properties() const {
    std::cout << r << " " << cx << " " << cy << " ";
    GraphicsObject::print_properties();
}

//setter
void Circle::set_r(const float r){this->r = r;}
void Circle::set_cx(const float cx){this->cx = cx;}
void Circle::set_cy(const float cy){this->cy = cy;}

//to svg return the svg syntax for Circle
std::string Circle::to_svg() const{
    std::string str = "<circle ";
    if (r != defCircle::r){
        str += "r=\"" +  std::to_string(r) + "\" ";
    }
    if (cx != defCircle::cx){
        str += "cx=\"" +  std::to_string(cx) + "\" ";
    }
    if (cy != defCircle::cy){
        str += "cy=\"" +  std::to_string(cy) + "\" ";
    }
    if (obj::get_stroke() != def::stroke){
        str += "stroke=\"" + obj::get_stroke() + "\" ";
    }
    if (obj::get_fill() != def::fill){
        str += "fill=\"" + obj::get_fill() + "\" ";
    }
    if (obj::get_strokewidth() != def::strokewidth){
        str += "stroke-width=\"" + std::to_string(obj::get_strokewidth()) + "\" ";
    }
    str += "/>";
    return str;
}

//drawing circle 
void Circle::draw(QPainter& painter) const {
    painter.setPen(QPen(QColor(obj::get_stroke().c_str()), obj::get_strokewidth()));
    painter.setBrush(QBrush(QColor(obj::get_fill().c_str())));
    painter.drawEllipse(cx-abs(r),cy-abs(r),2*abs(r),2*abs(r));
}

//update width and height while forming
void Circle::update_drag(const QPoint& start, const QPoint& end){
    float width = end.x() - start.x(); float height = end.y() - start.y(); 
    r = pow(((width*width) + (height*height)),(0.5));
}

//bounding rect
QRect Circle::bounding_rect() const {return QRect(cx-abs(r),cy-abs(r),2*abs(r),2*abs(r));}

//inside of rect
bool Circle::inside(const QPoint& point) const { return bounding_rect().contains(point);}

//move rect
void Circle::move(const float del_x, const float del_y){cx += del_x; cy += del_y;}

//copy with x and y 
GraphicsObject* Circle::clone(const float nx, const float ny) const {
    return new Circle(r, nx, ny, obj::get_stroke(), obj::get_fill(), obj::get_strokewidth());
}

Geometry Circle::get_geometry() const {
    Geometry g;
    g.x=cx-r; g.y=cy-r; g.width=2*r; g.height= 2*r;
    return g;
}

void Circle::set_geometry(const Geometry& g){
    r = std::min(abs(g.width),abs(g.height))/2.0f;
    if(g.height > 0) cy = g.y + r;
    else cy = g.y - r;
    if (g.width > 0) cx = g.x +r;
    else cx = g.x - r;
}
// void Circle::set_geometry(const Geometry& g)
// {
//     float left   = std::min(g.x, g.x + g.width);
//     float right  = std::max(g.x, g.x + g.width);
//     float top    = std::min(g.y, g.y + g.height);
//     float bottom = std::max(g.y, g.y + g.height);

//     float size = std::min(right - left, bottom - top);

//     // Important: preserve correct anchor
//     if (g.width < 0)
//         left = right - size;

//     if (g.height < 0)
//         top = bottom - size;

//     r = size / 2.0f;
//     cx = left + r;
//     cy = top + r;
// }
// int main(){
//     Circle defuaktCircle;
//     Circle cir(15.0,50.0,100.0,"red","none",2.0);
//     defuaktCircle.print_properties();
//     cir.print_properties();
//     std::cout << defuaktCircle.to_svg() << std::endl;
//     std::cout << cir.to_svg() << std::endl;
//     GraphicsObject* p = &cir;
//     p->print_properties();
//     return 0;
// }