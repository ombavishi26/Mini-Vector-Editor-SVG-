#include "ResizeCommand.h"

ResizeCommand::ResizeCommand(GraphicsObject* object, const Geometry& oldG, const Geometry& newG) :
    object(object), oldG(oldG), newG(newG) {};

void ResizeCommand::execute(){
    object -> set_geometry(newG);
}

void ResizeCommand::undo(){
    object->set_geometry(oldG);
}