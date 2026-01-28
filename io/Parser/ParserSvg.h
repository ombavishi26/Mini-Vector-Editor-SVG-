#pragma once
#include "../../Objects/Object.h"
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <cstdlib>

//parsing initiall line 
void parser_initial(const std::string& line, int i);

//function which takes input line , postion and gives a vector of pairs in which there are properties in string and their values in pair
std::vector<std::pair<std::string,std::string>> seperate (const std::string& line,int pos ,int i);


void parser_rect(const std::string& line,int pos, int i);
//parsing circle line and gi
circle* parser_circle(const std::string& line , int pos, int i);

std::vector<GraphicsObject*> load_svg (const std::string& filename);
