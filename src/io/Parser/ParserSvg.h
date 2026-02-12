#pragma once
#include "../../Objects/Object.h"
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <cstdlib>

class ParserSvg {
private:
    //parsing initiall line 
    void parser_initial(const std::string& line,int i);

    //function which takes input line , postion and gives a vector of pairs in which there are properties in string and their values in pair
    std::vector<std::pair<std::string,std::string>> seperate (const std::string& line,int pos );
    //helper for text parsing
    std::vector<std::pair<std::string,std::string>> seperate_text (const std::string& line,int pos );

    //parsing rec line of syntax 
    Rect* parser_rect(const std::string& input,int pos, int i);
    //parsing circle line and return pointer of ciircle
    Circle* parser_circle(const std::string& input, int pos, int i);
    //parsing line and return pointer of Line
    Line* parser_line (const std::string& input , int pos, int i);
    //parsing hexagon
    Hexagon* parser_hexagon(const std::string& input, int pos, int i);
    //parsing path and return pointer of path
    path* parser_path (const std::string& input , int pos, int i);
    //parsing text and return pointer of text
    text* parser_text (const std::string& input , int pos, int i);

public:
    //loadinf file and returning vector of GraphicsObject pointers
    std::vector<GraphicsObject*> load_svg (const std::string& filename);
};
