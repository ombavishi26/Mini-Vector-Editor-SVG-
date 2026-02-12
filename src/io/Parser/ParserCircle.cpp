#include "ParserSvg.h"
// using objcir = GraphicsObject::Circle;

//parsing Circle line of svg syntax
Circle* ParserSvg::parser_circle(const std::string& input ,int pos,int i){
    std::vector<std::pair<std::string,std::string>> properties;
    properties = seperate (input,pos); 
    Circle* cir = new Circle();
    for(const auto& attribute : properties){
        if (attribute.first == "r"){
            cir->set_r(std::stof(attribute.second));
        }
        else if (attribute.first == "cx"){
            cir->set_cx(std::stof(attribute.second));
        }
        else if (attribute.first == "cy"){
            cir->set_cy(std::stof(attribute.second));
        }
        else if (attribute.first == "stroke"){
            cir->set_stroke(attribute.second);
        }
        else if (attribute.first == "fill"){
            cir->set_fill(attribute.second);
        }
        else if (attribute.first == "stroke-width"){
            cir->set_sw(std::stof(attribute.second));
        }
        else {
            std::cerr << "Error at line " << i << ": unknown attribute '" << attribute.first << std::endl;
            // delete cir;
            exit(1);
            // return nullptr;
        }
    }
    // cir->print_properties();
    return cir;
}