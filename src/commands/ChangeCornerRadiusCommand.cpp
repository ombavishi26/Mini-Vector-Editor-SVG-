#include "ChangeCornerRadiusCommand.h"
#include "../Objects/rect.h"

ChangeCornerRadiusCommand::ChangeCornerRadiusCommand(Rect* r, const float oldrx, const float oldry, const float newrx, const float newry) :
    rec(r), oldrx(oldrx), oldry(oldry), newrx(newrx), newry(newry) {};

void ChangeCornerRadiusCommand::execute(){
    rec->set_rx(newrx);
    rec->set_ry(newry);
}

void ChangeCornerRadiusCommand::undo(){
    rec->set_rx(oldrx);
    rec->set_ry(oldry);
}