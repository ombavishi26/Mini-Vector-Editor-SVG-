#include "line.h"
namespace def = Default;
namespace defLine = Default::line;
using obj = GraphicsObject;

//constructor
Line::Line() : GraphicsObject(), x1(defLine::x1), y1(defLine::y1), x2(defLine::x2), y2(defLine::y2) {};
//note Line donot have fill property
Line::Line(const float x1, const float y1, const float x2, const float y2, const std::string& stroke, const float sw) 
           : GraphicsObject(stroke, "none", sw), x1(x1), y1(y1), x2(x2), y2(y2) {};

//destructor
Line::~Line() {};

//print properties
void Line::print_properties() const {
    std::cout << x1 << " " << y1 << " " << x2 << " " << y2 << " ";
    GraphicsObject::print_properties();
}

//setter
void Line::set_x1(const float x1){this->x1 = x1;}
void Line::set_y1(const float y1){this->y1 = y1;}
void Line::set_x2(const float x2){this->x2 = x2;}
void Line::set_y2(const float y2){this->y2 = y2;}

//to svg return the svg syntax for Line
std::string Line::to_svg() const {
    std::string str = "<line ";;
    if (x1 != defLine::x1){
        str += "x1=\"" +  std::to_string(x1) + "\" ";
    }   
    if (y1 != defLine::y1){
        str += "y1=\"" +  std::to_string(y1) + "\" ";
    }
    if (x2 != defLine::x2){
        str += "x2=\"" +  std::to_string(x2) + "\" ";
    }
    if (y2 != defLine::y2){
        str += "y2=\"" +  std::to_string(y2) + "\" ";
    }
    if (obj::get_stroke() != def::stroke){
        str += "stroke=\"" + obj::get_stroke() + "\" ";
    }
    if (obj::get_strokewidth() != def::strokewidth){
        str += "stroke-width=\"" + std::to_string(obj::get_strokewidth()) + "\" ";
    }
    str += "/>";
    return str;
}

//drawing Line 
void Line::draw(QPainter& painter) const {
    painter.setPen(QPen(QColor(obj::get_stroke().c_str()), obj::get_strokewidth()));
    painter.setBrush(QBrush(QColor(obj::get_fill().c_str())));
    painter.drawLine(x1, y1, x2, y2);
}

//update width and height while forming
void Line::update_drag(const QPoint& start, const QPoint& end){
    x1 = start.x(); y1 = start.y();
    x2 = end.x() ; y2 = end.y();
}

//bounding rect
QRect Line::bounding_rect() const {return QRect(x1, y1,x2-x1,y2-y1);}

//inside of rect
bool Line::inside(const QPoint& point) const { return bounding_rect().contains(point);}

//move rect
void Line::move(const float del_x, const float del_y){x1 += del_x;x2 += del_x; y2 += del_y; y1 += del_y;}

//copy with x and y 
GraphicsObject* Line::clone(const float nx, const float ny) const {
    float ax, ay;
    ax = (x1-x2)/2.0f; ay = (y1-y2)/2.0f;
    return new Line(nx+ax,ny+ay,nx-ax,ny-ay, obj::get_stroke(), obj::get_strokewidth());
}

Geometry Line::get_geometry() const
{
    Geometry g;
    float left = std::min(x1, x2);
    float right= std::max(x1, x2);
    float top = std::min(y1, y2);
    float bottom = std::max(y1, y2);
    g.x = left;
    g.y = top;
    g.width  = right - left;
    g.height = bottom - top;
    return g;
}

void Line::set_geometry(const Geometry& g)
{
    Geometry old = get_geometry();
    float oldLeft= old.x;
    float oldTop = old.y;
    float oldWidth = old.width;
    float oldHeight = old.height;
    float newLeft   = std::min(g.x, g.x + g.width);
    float newTop    = std::min(g.y, g.y + g.height);
    float newWidth  = std::abs(g.width);
    float newHeight = std::abs(g.height);
    float scaleX = (oldWidth  != 0) ? newWidth  / oldWidth  : 1.0f;
    float scaleY = (oldHeight != 0) ? newHeight / oldHeight : 1.0f;

    x1 = newLeft + (x1 - oldLeft) * scaleX;
    y1 = newTop  + (y1 - oldTop)  * scaleY;
    x2 = newLeft + (x2 - oldLeft) * scaleX;
    y2 = newTop  + (y2 - oldTop)  * scaleY;
}
// int main(){
//     Line defuaktLine;
//     Line lin(0.0,0.0,50.0,100.0,"red",2.0);
//     defuaktLine.print_properties();
//     lin.print_properties();
//     std::cout << defuaktLine.to_svg() << std::endl;
//     std::cout << lin.to_svg() << std::endl;
//     return 0;
// }