#include "ChangeSwCommand.h"

ChangeSwCommand::ChangeSwCommand(GraphicsObject* object, const float oldsw, const float newsw) :
    object(object), oldsw(oldsw), newsw(newsw) {};

void ChangeSwCommand::execute(){
    object->set_sw(newsw);
}

void ChangeSwCommand::undo(){object->set_sw(oldsw);}