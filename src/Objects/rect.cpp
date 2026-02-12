#include "rect.h"
namespace def = Default;
namespace defrect = Default::rect;
using obj = GraphicsObject;

//constructor
Rect::Rect() : GraphicsObject(),width(defrect::width), height(defrect::height), x(defrect::x), y(defrect::y), rx(defrect::rx), ry(defrect::ry) {};
Rect::Rect(const float w, const float h, const float x, const float y, const float rx, const float ry, const std::string& stroke, const std::string& fill, const float sw) 
           : GraphicsObject(stroke, fill, sw), width(w), height(h), x(x), y(y), rx(rx), ry(ry) {};

//destructor
Rect::~Rect() {};

//print properties
void Rect::print_properties() const{
    std::cout << width << " " << height << " " << x << " " << y << " " << rx << " " << ry << " " ;
    GraphicsObject::print_properties();   
    // std::cout << std::endl;
}
//setter
void Rect::set_width(const float width){this->width = width;}
void Rect::set_height(const float height){this->height = height;}
void Rect::set_x(const float x){this->x = x;}
void Rect::set_y(const float y){this->y = y;}
void Rect::set_rx(const float rx){this->rx = rx;}
void Rect::set_ry(const float ry){this->ry = ry;}


//getter
int Rect::get_width() const {return width;}
int Rect::get_height() const {return height;}
int Rect::get_x() const {return x;}
int Rect::get_y() const {return y;}
int Rect::get_rx() const {return rx;}
int Rect::get_ry() const {return ry;}

//to svg return the svg syntax for rect
std::string Rect::to_svg() const {
    std::string str ="<rect ";
    if(width != defrect::width){
        str += "width=\"" + std::to_string(width) + "\" ";
    }
    if (height != defrect::height){
        str += "height=\"" + std::to_string(height) + "\" ";
    }
    if (x != defrect::x){
        str += "x=\"" + std::to_string(x) + "\" ";
    }
    if (y != defrect::y){
        str += "y=\"" + std::to_string(y) + "\" ";
    }
    if (rx != defrect::rx){
        str += "rx=\"" + std::to_string(rx) + "\" ";
    }
    if (ry != defrect::ry){
        str += "ry=\"" + std::to_string(ry) + "\" ";
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

//drawing rect
void Rect::draw(QPainter& painter) const {
    painter.setPen(QPen(QColor(obj::get_stroke().c_str()), obj::get_strokewidth()));
    painter.setBrush(QBrush(QColor(obj::get_fill().c_str())));
    painter.drawRoundedRect(x, y, width, height, rx, ry);
}

//update width and height while forming
void Rect::update_drag(const QPoint& start, const QPoint& end){
    width = end.x() - start.x(); height = end.y() - start.y(); 
}

//bounding rect
QRect Rect::bounding_rect() const {return QRect(x, y, width, height);}

//inside of rect
bool Rect::inside(const QPoint& point) const { return bounding_rect().contains(point);}

//move rect
void Rect::move(const float del_x, const float del_y){x += del_x; y += del_y;}

//copy with x and y 
GraphicsObject* Rect::clone(const float nx, const float ny) const {
    return new Rect(width, height, nx, ny, rx, ry, obj::get_stroke(), obj::get_fill(), obj::get_strokewidth());
}

Geometry Rect::get_geometry() const {
    Geometry g;
    g.x=x; g.y=y; g.height=height; g.width= width;
    return g;
}

void Rect::set_geometry(const Geometry& g){
    x=g.x; y=g.y; width=g.width; height=g.height;
}

// int main (){
//     rect defaultrect;
//     rect rec(12,11,2,3,4,5,"red","orange");
//     defaultrect.set_fill("blue");
//     defaultrect.print_properties();
//     rec.set_height(20);
//     rec.print_properties();
//     std::cout << defaultrect.to_svg() << std::endl;
//     std::cout << rec.to_svg() << std::endl;
//     return 0;
// }

// <svg width="200" height="200" xmlns="http://www.w3.org/2000/svg">

//   <circle cx="50" cy="100" r="30" stroke="red" stroke-width="2" fill="none"/>

//   <circle cx="130" cy="100" r="30" stroke="blue" stroke-width="2" fill="yellow"/>

// </svg>
