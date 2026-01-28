#include "ParserSvg.h"

//parsing initial line
void parser_initial(const std::string& line, int i){
    //seeing <svg 
    if (line.find("<svg") != 0 ){
        std::cerr << "error on line " << i << "initial line must start with '<' " << std::endl;
        exit(1);
        return;
    }
    //checking closing of line
    if (line.find('>') != line.length() -1){
        std::cerr  << "error on line " << i << "initial line nust end with '>' " << std::endl;
        exit(1);
        return ;
    }
}

std::vector<GraphicsObject*> load_svg (const std::string& filename){
    std::ifstream file(filename);
    std::vector<GraphicsObject*> objects;
    //Checking for correctly open file
    if (!file.is_open()) {
        std::cerr << "Error:Could not open file " << filename << std::endl;
        return objects;
    }

    //number of line if error find 
    int err_index = 1;

    //reading first line 
    std::string line;
    std::getline(file,line); 
    std::cout << line << std::endl; 
    parser_initial(line,err_index);

    //do something till line is not last line ehich is </svg>
    while (line != "</svg>"){
        std::getline(file,line);

        std::cout << line << std::endl;
    }

    file.close();
    return objects;
};

int main(){
    std::vector<GraphicsObject*> objects = load_svg("output.svg");
    return 0;
}