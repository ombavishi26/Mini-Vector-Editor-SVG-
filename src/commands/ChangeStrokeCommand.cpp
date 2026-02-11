#include "ChangeStrokeCommand.h"

ChangeStrokeCommand::ChangeStrokeCommand(GraphicsObject* object, const std::string& oldStroke, const std::string& newStroke) :
    object(object), oldStroke(oldStroke), newStroke(newStroke) {};

void ChangeStrokeCommand::execute(){
    object->set_stroke(newStroke);
}

void ChangeStrokeCommand::undo(){
    object->set_stroke(oldStroke);
}