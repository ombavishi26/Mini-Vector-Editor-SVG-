#include <iostream>
#include <string>   

class GraphicsObject {
private:
    std::string stroke;
    std::string fill;
    float strokeWidth;

public:
    // Constructor
    GraphicsObject();
    GraphicsObject(const std::string& strokeColor, const std::string& fillColor, float sw);
    // Destructor
    ~GraphicsObject();
    // Print properties
    void printProperties() const;
}