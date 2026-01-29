#include "ParserSvg.h"

//parsing path syntax of svg 
path* parser_path (const std::string& input , int pos, int i){
    std::vector<std::pair<std::string,std::string>> properties;
    properties = seperate (input,pos); 
    path* p = new path();
    for (const auto& attribute : properties){
        if (attribute.first == "d"){
            p->set_d(attribute.second);
        }
        else if (attribute.first == "stroke"){
            p->set_stroke(attribute.second);
        }
        else if (attribute.first == "fill"){
            p->set_fill(attribute.second);
        }
        else if (attribute.first == "stroke-width"){
            p->set_sw(std::stof(attribute.second));
        }
        else {
            std::cerr << "Error at line " << i << ": unknown attribute '" << attribute.first << std::endl;
            delete p;
            exit(1);
            return nullptr;
        }
    }
    // p->print_properties();
    return p;
}