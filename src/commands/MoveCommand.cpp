#include "MoveCommand.h"

MoveCommand::MoveCommand(GraphicsObject* o, float dx, float dy) :
    object(o), delx(dx) , dely(dy){};

void MoveCommand::execute(){
    object -> move(delx, dely);
}

void MoveCommand::undo(){
    object->move(-delx, -dely);
}
