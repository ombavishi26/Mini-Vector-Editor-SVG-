#include "ParserSvg.h"

//parsing line syntax of svg 
line* parser_line (const std::string& input , int pos, int i){
    std::vector<std::pair<std::string,std::string>> properties;
    properties = seperate (input,pos); 
    line* lin = new line();
    for (const auto& attribute : properties){
        if (attribute.first == "x1"){
            lin->set_x1(std::stof(attribute.second));
        }
        else if (attribute.first == "y1"){
            lin->set_y1(std::stof(attribute.second));
        }
        else if (attribute.first == "x2"){
            lin->set_x2(std::stof(attribute.second));
        }
        else if (attribute.first == "y2"){
            lin->set_y2(std::stof(attribute.second));
        }
        else if (attribute.first == "stroke"){
            lin->set_stroke(attribute.second);
        }
        else if (attribute.first == "stroke-width"){
            lin->set_sw(std::stof(attribute.second));
        }
        else {
            std::cerr << "Error at line " << i << ": unknown attribute '" << attribute.first << std::endl;
            delete lin;
            exit(1);
            return nullptr;
        }
    }
    lin->print_properties();
    return lin;
}