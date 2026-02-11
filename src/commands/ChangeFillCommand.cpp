#include "ChangeFillCommand.h"

ChangeFillCommand::ChangeFillCommand(GraphicsObject* object, std::string oldFill, std::string newFill) : 
    object(object), oldFill(oldFill), newFill(newFill) {};

void ChangeFillCommand::execute(){
    object->set_fill(newFill);
}

void ChangeFillCommand::undo(){
    object->set_fill(oldFill);
}