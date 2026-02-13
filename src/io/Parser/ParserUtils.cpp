#include "ParserSvg.h"

//helper function to seperate properties and their values from a line
// used for rect,circle,line,path
std::vector<std::pair<std::string,std::string>> ParserSvg::seperate (const std::string& line,int pos){
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
std::vector<std::pair<std::string,std::string>> ParserSvg::seperate_text (const std::string& line,int pos ){
    std::vector<std::pair<std::string,std::string>> properties;
    std::pair<std::string,std::string> attribute;

    while (size_t(pos+2) < line.length() && line.substr(pos,1) != ">"){

        // std::cout << "1";
        int pos_equal = line.find('=',pos);
        if(pos_equal == std::string::npos)
            break;

        std::string property = line.substr(pos,pos_equal-pos);
        attribute.first = property;

        int pos_quote = line.find('"',pos_equal+1);
        if(pos_quote == std::string::npos)
            break;

        int pos_quote2 = line.find('"',pos_quote+1);
        if(pos_quote2 == std::string::npos)
            break;

        std::string value = line.substr(pos_quote+1,pos_quote2-(pos_quote+1));
        attribute.second = value;
        properties.push_back(attribute);
        pos = pos_quote2+1;

        while(pos < line.length() && line[pos] == ' ')
            pos++;
    }
    int start_content = line.find('>');
    int pos_end = line.find("</text>");
    if(pos_end == std::string::npos){
        throw std::runtime_error("Error: </text> not found");
    }
    std::string content = line.substr(start_content+1,pos_end-(start_content+1));
    attribute.first = "content";
    attribute.second = content;
    properties.push_back(attribute);

    return properties;
}

// void print(std::vector<std::pair<std::string,std::string>> properties){
//     for(auto a:properties){
//         std::cout << a.first << " " << a.second << std::endl;
//     }
// }
// int main(){
//     std::vector<std::pair<std::string,std::string>> properties;
//     std::string a = R"(<text x="213.000000" y="235.000000" rotate="0.000000" font-size="35" stroke="#ff4398" fill="#0a2bff" stroke-width="2.000000">hagdfjjha</text>)";
//     properties = seperate_text(a,6);
//     print(properties);
// }