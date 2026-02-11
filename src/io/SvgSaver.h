#pragma once
#include "../Objects/Object.h"
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>

class SvgSaver {
public:
    static void svg_saver(const std::string& filename, std::vector<GraphicsObject*>& objects);
};