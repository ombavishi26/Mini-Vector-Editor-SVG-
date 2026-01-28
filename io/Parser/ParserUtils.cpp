#include "ParserSvg.h"

//helper function to seperate properties and their values from a line
//used for rect,circle,line,path
std::vector<std::pair<std::string,std::string>> seperate (const std::string& line,int pos , int i){
    std::vector<std::pair<std::string,std::string>> properties;
    while (line.substr(pos,2) != "/>"){
        std::pair<std::string,std::string> attribute;

        //finding pos of = so between is property
        int pos_equal = line.find('=',pos);
        std::string property = line.substr(pos,pos_equal-pos);
        attribute.first = property;
        // std::cout << property << "aaa" << std::endl;

        //finding pos of second " for value of property
        int pos_quote = line.find('"',pos_equal+2);
        std::string value = line.substr(pos_equal+2,pos_quote -(pos_equal+2));
        // std::cout << value << "aaa" <<std::endl;
        attribute.second = value;

        //pushing back to vector
        properties.push_back(attribute);
        pos = pos_quote+2;
    }
    return properties;
}