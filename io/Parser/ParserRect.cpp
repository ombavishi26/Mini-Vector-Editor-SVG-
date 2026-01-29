#include "ParserSvg.h"

//parsing rect line of svg syntax
rect* parser_rect (const std::string& input , int pos, int i){
    std::vector<std::pair<std::string,std::string>> properties;
    properties = seperate (input,pos); 
    rect* rec = new rect();
    for (const auto& attribute : properties){
        if (attribute.first == "width"){
            rec->set_width(std::stof(attribute.second));
        }
        else if (attribute.first == "height"){
            rec->set_height(std::stof(attribute.second));
        }
        else if (attribute.first == "x"){
            rec->set_x(std::stof(attribute.second));
        }
        else if (attribute.first == "y"){
            rec->set_y(std::stof(attribute.second));
        }
        else if (attribute.first == "rx"){
            rec->set_rx(std::stof(attribute.second));
        }
        else if (attribute.first == "ry"){
            rec->set_ry(std::stof(attribute.second));
        }
        else if (attribute.first == "stroke"){
            rec->set_stroke(attribute.second);
        }
        else if (attribute.first == "fill"){
            rec->set_fill(attribute.second);
        }
        else if (attribute.first == "stroke-width"){
            rec->set_sw(std::stof(attribute.second));
        }
        else {
            std::cerr << "Error at line " << i << ": unknown attribute '" << attribute.first << std::endl;
            delete rec;
            exit(1);
            return nullptr;
        }
    }
    // rec->print_properties();
    return rec;
}