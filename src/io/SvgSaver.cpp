#include "SvgSaver.h"

void SvgSaver::svg_saver(const std::string& filename, std::vector<GraphicsObject*>& objects){
    std::ofstream file(filename);
    //Checking for correctly open file
    if (!file.is_open()) {
        std::cout << "Error:Could not open file " << filename << std::endl;
        return;
    }
    file << "<svg width=\"200\" height=\"200\" xmlns=\"http://www.w3.org/2000/svg\" >" << std::endl;
    // std::vector<GraphicsObject*> objects_copy = objects;
    for (int i = 0; i < objects.size(); ++i){
        if (objects[i] != nullptr) {
            file << objects[i]->to_svg() << std::endl;
        }
    }
    file << "</svg>" << std::endl;
    file.close();
}

// int main(){
//     std::vector<GraphicsObject*> objects;
//     objects.push_back(new rect());
//     objects.push_back(new circle(30.0,50.0,50.0,"red","blue",2.0));
//     objects.push_back(new line(10.0,10.0,100.0,100.0,"green",1.5));
//     objects.push_back(new path("M10 10 H 90 V 90 H 10 L 10 10","purple","yellow",2.0));
//     objects.push_back(new text(20.0,30.0,0.0,0.0,0.0,14,"Sample Text","black","none",1.0));
//     svg_saver("output.svg",objects);
//     return 0;
// }