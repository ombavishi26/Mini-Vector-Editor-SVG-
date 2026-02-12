#pragma once
#include "Command.h"

class Rect;

class ChangeCornerRadiusCommand : public Command{
private:
    Rect* rec;
    float oldrx,oldry, newrx, newry;

public:
    ChangeCornerRadiusCommand(Rect* rect, const float oldrx, const float oldry, const float newrx, const float newry);
    ~ChangeCornerRadiusCommand(){};

    void execute() override;
    void undo() override;
};