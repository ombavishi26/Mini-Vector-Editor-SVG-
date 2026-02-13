#include "text.h"
#include <QPainterPath>
using obj = GraphicsObject;
namespace def = Default;
namespace deftext = Default::text;

//constructor
Text::Text() : GraphicsObject() , x(deftext::x),y(deftext::y),rotate(deftext::rotate),font_size(deftext::font_size) , content(deftext::content) {};
Text::Text(const float x,const float y,const float rotate, const int font_size, const std::string& content,const std::string& stroke,const std::string& fill, const float sw) 
        : GraphicsObject(stroke,fill,sw) , x(x),y(y),rotate(rotate),font_size(font_size),content(content) {};

//destructor
Text::~Text() {};

//print properties
void Text::print_properties() const {
    std::cout << x << ' ' << y << ' ' << rotate << ' ' << font_size << ' ' << content << ' ';
    obj::print_properties();
}

//setter
void Text::set_x(const float x){this->x = x;}
void Text::set_y(const float y){this->y = y;}
void Text::set_rotate(const float rotate){this->rotate = rotate;}
void Text::set_font_size(const int font_size){this->font_size = font_size;}
void Text::set_content(const std::string& content){this->content = content;}

//to_svg return string for svg sntax of font 
std::string Text::to_svg() const{
    std::string str = "<text ";
    if (x != deftext::x){
        str += "x=\"" + std::to_string(x) + "\" ";
    }
    if (y != deftext::y){
        str += "y=\"" + std::to_string(y) + "\" ";
    }
    if (rotate != deftext::rotate){
        str += "rotate=\"" + std::to_string(rotate) + "\" ";
    }
    if (font_size != deftext::font_size){
        str += "font-size=\"" + std::to_string(font_size) + "\" ";
    }
    if (obj::get_stroke() != def::stroke){
        str += "stroke=\"" + obj::get_stroke() + "\" ";
    }
    if (obj::get_fill() != def::fill){
        str += "fill=\"" + obj::get_fill() + "\" ";
    }
    if (obj::get_strokewidth() != def::strokewidth){
        str += "stroke-width=\"" + std::to_string(obj::get_strokewidth()) + "\"";
    }
    str += ">" + content + "</text>";
    return str;
}

//drawing Text 
void Text::draw(QPainter& painter) const {
    QFont font;
    font.setPointSize(font_size);
    QPainterPath path;
    path.addText(x, y + font_size, font, QString::fromStdString(content));
    painter.save();
    QRect rect = bounding_rect();
    QPoint center = rect.center();
    painter.translate(center);
    painter.rotate(rotate);
    painter.translate(-center);
    painter.setBrush(QColor(obj::get_fill().c_str()));
    painter.setPen(QPen(QColor(obj::get_stroke().c_str()), obj::get_strokewidth()));
    painter.drawPath(path);
}

//update width and height while forming
// void Text::update_drag(const QPoint& start, const QPoint& end){
//     float width = end.x() - start.x(); float height = end.y() - start.y(); 
//     r = pow(((width*width) + (height*height)),(0.5));
// }

//bounding rect
QRect Text::bounding_rect() const {
    QFont font;
    font.setPointSize(font_size);
    QPainterPath path;
    path.addText(x, y + font_size, font, QString::fromStdString(content));
    return path.boundingRect().toRect();
}

//inside of rect
bool Text::inside(const QPoint& point) const { return bounding_rect().contains(point);}

//move rect
void Text::move(const float del_x, const float del_y){x += del_x; y += del_y;}

//copy with x and y 
GraphicsObject* Text::clone(const float nx, const float ny) const {
    return new Text(nx, ny, rotate, font_size, content, obj::get_stroke(), obj::get_fill(), obj::get_strokewidth());
}

Geometry Text::get_geometry() const {
    QRect rect = bounding_rect();
    Geometry g;
    g.x = rect.x();
    g.y = rect.y();
    g.width = rect.width();
    g.height = rect.height();
    return g;
}

void Text::set_geometry(const Geometry& g){
    x = g.x;
    y = g.y;
}

// int main(){
//     text defuakttext;
//     text tx(10.0,20.0,15.0,16,"Hello, SVG!","red","blue",2.0);
//     defuakttext.print_properties();
//     tx.print_properties();
//     std::cout << defuakttext.to_svg() << std::endl;
//     std::cout << tx.to_svg() << std::endl;
//     return 0;
// }