#include "ParserSvg.h"

//helper function to seperate properties and their values from a line
//used for rect,circle,line,path
std::vector<std::pair<std::string,std::string>> seperate (const std::string& line,int pos){
    std::vector<std::pair<std::string,std::string>> properties;
    while (size_t(pos+2) < line.length() && line.substr(pos,2) != "/>"){
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

//helper for text parsing
std::vector<std::pair<std::string,std::string>> seperate_text (const std::string& line,int pos ){
    std::vector<std::pair<std::string,std::string>> properties;
    std::pair<std::string,std::string> attribute;

    while (size_t(pos+2) < line.length() && line.substr(pos,1) != ">"){

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

    //getting text content
    int pos_end = line.find("</text>");
    if(line.find("</text>") == std::string::npos){
        throw std::runtime_error("Error: </text> not found");
        exit(1);
    }
    std::string content = line.substr(pos+1,pos_end-(pos+1));
    attribute.first = "content";
    attribute.second = content;
    properties.push_back(attribute);
    // std::cout << content << "aaa" <<std::endl;
    return properties;
}
