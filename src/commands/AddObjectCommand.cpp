#include "AddObjectCommand.h"

AddObjectCommand::AddObjectCommand(std::vector<GraphicsObject*>& objects, GraphicsObject* object) : objects(objects), object(object) {}

void AddObjectCommand::execute(){
    objects.push_back(object);
}

void AddObjectCommand::undo(){
    auto it = std::find(objects.begin(), objects.end(), object);
    if (it != objects.end()) objects.erase(it);
}
