#include "text.h"
using obj = GraphicsObject;
namespace def = Default;
namespace deftext = Default::text;

//constructor
text::text() : GraphicsObject() , x(deftext::x),y(deftext::y),dx(deftext::dx),dy(deftext::dy),rotate(deftext::rotate),font_size(deftext::font_size) , content(deftext::content) {};
text::text(const float x,const float y,const float dx,const float dy,const float rotate, const int font_size, const std::string& content,const std::string& stroke,const std::string& fill, const float sw) 
        : GraphicsObject(stroke,fill,sw) , x(x),y(y),dx(dx),dy(dy),rotate(rotate),font_size(font_size),content(content) {};
//destructor
text::~text() {};

//print properties
void text::print_properties() const {
    std::cout << x << ' ' << y << ' ' << dx << ' ' << dy << ' ' << rotate << ' ' << font_size << ' ' << content << ' ';
    obj::print_properties();
}

//to_svg return string for svg sntax of font 
std::string text::to_svg() const{
    std::string str = "<text ";
    if (x != deftext::x){
        str += "x=\"" + std::to_string(x) + "\" ";
    }
    if (y != deftext::y){
        str += "y=\"" + std::to_string(y) + "\" ";
    }
    if (dx != deftext::dx){
        str += "dx=\"" + std::to_string(dx) + "\" ";
    }
    if (dy != deftext::dy){
        str += "dy=\"" + std::to_string(dy) + "\" ";
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

int main(){
    text defuakttext;
    text tx(10.0,20.0,5.0,5.0,15.0,16,"Hello, SVG!","red","blue",2.0);
    defuakttext.print_properties();
    tx.print_properties();
    std::cout << defuakttext.to_svg() << std::endl;
    std::cout << tx.to_svg() << std::endl;
    return 0;
}