#pragma once 
#include "Command.h"

class ResizeCommand : public Command {
private:
    GraphicsObject* object;
    Geometry oldG, newG;

public:
    ResizeCommand(GraphicsObject* object, const Geometry& oldG, const Geometry& newG);
    ~ResizeCommand(){};

    void execute();
    void undo();
};