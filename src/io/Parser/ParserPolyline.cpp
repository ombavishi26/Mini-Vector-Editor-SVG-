#include "ParserSvg.h"

Polyline* ParserSvg::parser_polyline(const std::string& input ,int pos,int i){
    std::vector<std::pair<std::string,std::string>> properties;
    properties = seperate(input,pos); 
    std::vector<std::pair<float,float>> pts;
    Polyline* poly = new Polyline();
    for(const auto& attribute : properties){
        if(attribute.first == "points"){
            std::string value = attribute.second;
            std::stringstream ss(value);
            std::string pair;
            while(ss >> pair){
                size_t comma = pair.find(',');
                if(comma == std::string::npos) continue;
                float x = std::stof(pair.substr(0,comma));
                float y = std::stof(pair.substr(comma+1));
                pts.push_back({x,y});
            }
            poly->set_points(pts);
        }
        else if(attribute.first == "stroke"){
            poly->set_stroke(attribute.second);
        }
        else if(attribute.first == "fill"){
            poly->set_fill(attribute.second);
        }
        else if(attribute.first == "stroke-width"){
            poly->set_sw(std::stof(attribute.second));
        }
        else{
            std::cerr << "Error at line " << i << ": unknown attribute '" << attribute.first << "'" << std::endl;
            delete poly;
            exit(1);
            return nullptr;
        }
    }
    // poly->print_properties();
    return poly;
}