#include "ParserSvg.h"

//parsing text line of svg 
text* ParserSvg::parser_text(const std::string& input ,int pos,int i){
    std::vector<std::pair<std::string,std::string>> properties;
    properties = seperate_text(input,pos); 
    text* t = new text();
    for(const auto& attribute : properties){
        if (attribute.first == "x"){
            t->set_x(std::stof(attribute.second));
        }
        else if (attribute.first == "y"){
            t->set_y(std::stof(attribute.second));
        }
        else if (attribute.first == "dx"){
            t->set_dx(std::stof(attribute.second));
        }
        else if (attribute.first == "dy"){
            t->set_dy(std::stof(attribute.second));
        }
        else if (attribute.first == "rotate"){
            t->set_rotate(std::stof(attribute.second));
        }
        else if (attribute.first == "content"){
            t->set_content(attribute.second);
        }
        else if (attribute.first == "font-size"){
            t->set_font_size(std::stof(attribute.second));
        }
        else if (attribute.first == "stroke"){
            t->set_stroke(attribute.second);
        }
        else if (attribute.first == "fill"){
            t->set_fill(attribute.second);
        }
        else if (attribute.first == "stroke-width"){
            t->set_sw(std::stof(attribute.second));
        }
        else {
            std::cerr << "Error at line " << i << ": unknown attribute '" << attribute.first << std::endl;
            delete t;
            exit(1);
            return nullptr;
        }
    }
    // t->print_properties();
    return t;
}