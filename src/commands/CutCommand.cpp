#include "CutCommand.h"
#include <algorithm>

CutCommand::CutCommand(std::vector<GraphicsObject*>& objs, GraphicsObject* object) :
    objects(objs), object(object) , index(0) {};

void CutCommand::execute(){
    auto obj = std::find(objects.begin(),objects.end(), object);
    if (obj != objects.end()){
        index = std::distance(objects.begin(), obj);
        objects.erase(obj);
    }
}

void CutCommand::undo(){
    objects.insert(objects.begin() + index, object);
}