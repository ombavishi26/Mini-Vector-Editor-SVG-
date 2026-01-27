#include <iostream>
#include <string>   

class GraphicsObject {
private:
    std::string stroke;
    std::string fill;
    float strokewidth;

public:
    // Constructor
    GraphicsObject();
    GraphicsObject(const std::string& strokeColor, const std::string& fillColor, float sw);
    // Destructor
    ~GraphicsObject();
    // Print properties
    void print_properties() const;
    //getter
    std::string get_stroke();
    std::string get_fill();
    float get_strokewidth();
};