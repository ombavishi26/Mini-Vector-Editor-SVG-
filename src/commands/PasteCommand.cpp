#include "PasteCommand.h"

PasteCommand::PasteCommand(std::vector<GraphicsObject*>& objects, GraphicsObject* object) :
    objects(objects), object(object) {};

void PasteCommand::execute(){
    objects.push_back(object);
}

void PasteCommand::undo(){
    auto obj = std::find(objects.begin(), objects.end(), object);
    if(obj != objects.end()){
        objects.erase(obj);
    }
}