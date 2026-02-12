#include "ParserSvg.h"
// using objcir = GraphicsObject::Hexagon;

//parsing Circle line of svg syntax
Hexagon* ParserSvg::parser_hexagon(const std::string& input ,int pos,int i){
    std::vector<std::pair<std::string,std::string>> properties;
    properties = seperate (input,pos); 
    Hexagon* hex = new Hexagon();
    for(const auto& attribute : properties){
        if (attribute.first == "r"){
            hex->set_r(std::stof(attribute.second));
        }
        else if (attribute.first == "cx"){
            hex->set_cx(std::stof(attribute.second));
        }
        else if (attribute.first == "cy"){
            hex->set_cy(std::stof(attribute.second));
        }
        else if (attribute.first == "stroke"){
            hex->set_stroke(attribute.second);
        }
        else if (attribute.first == "fill"){
            hex->set_fill(attribute.second);
        }
        else if (attribute.first == "stroke-width"){
            hex->set_sw(std::stof(attribute.second));
        }
        else {
            std::cerr << "Error at line " << i << ": unknown attribute '" << attribute.first << std::endl;
            // delete cir;
            exit(1);
            // return nullptr;
        }
    }
    // cir->print_properties();
    return hex;
}