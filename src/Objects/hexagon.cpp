#include "hexagon.h"
#include <cmath>
namespace def = Default;
namespace defHexagon = Default::Hexagon;
using obj = GraphicsObject;

//constructor
Hexagon::Hexagon() : GraphicsObject(), r(defHexagon::r), cx(defHexagon::cx), cy(defHexagon::cy) {};
Hexagon::Hexagon(const float r, const float cx, const float cy, const std::string& stroke, const std::string& fill, const float sw) 
           : GraphicsObject(stroke, fill, sw), r(r), cx(cx), cy(cy) {};

//destructor
Hexagon::~Hexagon() {};

//print properties
void Hexagon::print_properties() const {
    std::cout << r << " " << cx << " " << cy << " ";
    GraphicsObject::print_properties();
}

//setter
void Hexagon::set_r(const float r){this->r = r;}
void Hexagon::set_cx(const float cx){this->cx = cx;}
void Hexagon::set_cy(const float cy){this->cy = cy;}

//to svg return the svg syntax for Hexagon
std::string Hexagon::to_svg() const{
    std::string str = "<hexagon ";
    if (r != defHexagon::r){
        str += "r=\"" +  std::to_string(r) + "\" ";
    }
    if (cx != defHexagon::cx){
        str += "cx=\"" +  std::to_string(cx) + "\" ";
    }
    if (cy != defHexagon::cy){
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

//drawing Hexagon 
void Hexagon::draw(QPainter& painter) const {
    painter.setPen(QPen(QColor(obj::get_stroke().c_str()), obj::get_strokewidth()));
    painter.setBrush(QBrush(QColor(obj::get_fill().c_str())));
    QPolygonF poly;
    for (int i = 0; i < 6; ++i) {
        double angle = M_PI / 3.0 * i;
        double x = cx + r * cos(angle);
        double y = cy + r * sin(angle);
        poly << QPointF(x, y);
    }
    painter.drawPolygon(poly);
}

//update width and height while forming
void Hexagon::update_drag(const QPoint& start, const QPoint& end){
    float width = end.x() - start.x(); float height = end.y() - start.y(); 
    r = pow(((width*width) + (height*height)),(0.5));
}

//bounding rect
QRect Hexagon::bounding_rect() const {return QRect(cx-abs(r),cy-abs(r),2*abs(r),2*abs(r));}

//inside of rect
bool Hexagon::inside(const QPoint& point) const { return bounding_rect().contains(point);}

//move rect
void Hexagon::move(const float del_x, const float del_y){cx += del_x; cy += del_y;}

//copy with x and y 
GraphicsObject* Hexagon::clone(const float nx, const float ny) const {
    return new Hexagon(r, nx, ny, obj::get_stroke(), obj::get_fill(), obj::get_strokewidth());
}

Geometry Hexagon::get_geometry() const {
    Geometry g;
    g.x=cx-r; g.y=cy-r; g.width=2*r; g.height= 2*r;
    return g;
}

void Hexagon::set_geometry(const Geometry& g){
    r = std::min(abs(g.width),abs(g.height))/2.0f;
    if(g.height > 0) cy = g.y + r;
    else cy = g.y - r;
    if (g.width > 0) cx = g.x +r;
    else cx = g.x - r;
}
// void Hexagon::set_geometry(const Geometry& g)
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
//     Hexagon defuaktHexagon;
//     Hexagon cir(15.0,50.0,100.0,"red","none",2.0);
//     defuaktHexagon.print_properties();
//     cir.print_properties();
//     std::cout << defuaktHexagon.to_svg() << std::endl;
//     std::cout << cir.to_svg() << std::endl;
//     GraphicsObject* p = &cir;
//     p->print_properties();
//     return 0;
// }