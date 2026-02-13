#include "polyline.h"
namespace def = Default;
using obj = GraphicsObject;

//constructor
Polyline::Polyline() : GraphicsObject() {};
Polyline::Polyline(const std::vector<std::pair<float,float>>& points, const std::string& stroke, const std::string& fill, const float sw)
    : GraphicsObject(stroke, fill, sw), points(points) {};

//destructor
Polyline::~Polyline() {};

//print properties
void Polyline::print_properties() const {
    for(const auto& p : points){
        std::cout << p.first << " " << p.second << " ";
    }
    GraphicsObject::print_properties();
}

//setter
void Polyline::set_points(const std::vector<std::pair<float,float>>& pts){
    this->points = pts;
}

void Polyline::add_point(const float x,const float y){
    points.push_back({x,y});
}

//to svg return the svg syntax for Polyline
std::string Polyline::to_svg() const{
    std::string str = "<polyline ";
    str += "points=\"";
    for(const auto& p : points){
        str += std::to_string(p.first) + "," + std::to_string(p.second) + " ";
    }
    str += "\" ";

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

//drawing polyline
void Polyline::draw(QPainter& painter) const {
    painter.setPen(QPen(QColor(obj::get_stroke().c_str()), obj::get_strokewidth()));
    painter.setBrush(Qt::NoBrush);
    QPolygonF poly;
    for(const auto& p : points){
        poly << QPointF(p.first,p.second);
    }
    painter.drawPolyline(poly);
}

//update while forming
void Polyline::update_drag(const QPoint& start, const QPoint& end){
    if(points.empty())
        points.push_back({(float)start.x(),(float)start.y()});
    points.push_back({(float)end.x(),(float)end.y()});
}

//bounding rect
QRect Polyline::bounding_rect() const {
    if(points.empty()) return QRect();
    float min_x = points[0].first;
    float max_x = points[0].first;
    float min_y = points[0].second;
    float max_y = points[0].second;
    for(const auto& p : points){
        min_x = std::min(min_x,p.first);
        max_x = std::max(max_x,p.first);
        min_y = std::min(min_y,p.second);
        max_y = std::max(max_y,p.second);
    }
    return QRect(min_x,min_y,max_x-min_x,max_y-min_y);
}

//inside of polyline
bool Polyline::inside(const QPoint& point) const {
    return bounding_rect().contains(point);
}

//move polyline
void Polyline::move(const float del_x, const float del_y){
    for(auto& p : points){
        p.first += del_x;
        p.second += del_y;
    }
}

//copy with x and y (shift first point anchor)
GraphicsObject* Polyline::clone(const float nx, const float ny) const {
    std::vector<std::pair<float,float>> new_points = points;
    if(!new_points.empty()){
        float dx = nx - new_points[0].first;
        float dy = ny - new_points[0].second;
        for(auto& p : new_points){
            p.first += dx;
            p.second += dy;
        }
    }
    return new Polyline(new_points, obj::get_stroke(), obj::get_fill(), obj::get_strokewidth());
}

Geometry Polyline::get_geometry() const {
    QRect rect = bounding_rect();
    Geometry g;
    g.x = rect.x();
    g.y = rect.y();
    g.width = rect.width();
    g.height = rect.height();
    return g;
}

void Polyline::set_geometry(const Geometry& g){
    QRect rect = bounding_rect();
    float dx = g.x - rect.x();
    float dy = g.y - rect.y();
    move(dx,dy);
}