#pragma once
#include "../Objects/Object.h"
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>

void save_svg(const std::string& filename, const std::vector<GraphicsObject*>& objects);