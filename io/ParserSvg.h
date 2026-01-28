#pragma once
#include "../Objects/Object.h"
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <cstdlib>

//parsing initiall line 
void parser_initial(const std::string& line, int i);

std::vector<GraphicsObject*> load_svg (const std::string& filename);
