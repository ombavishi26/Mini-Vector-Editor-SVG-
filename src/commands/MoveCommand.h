#pragma once
#include "Command.h"

class MoveCommand : public Command{
private:
    GraphicsObject* object;
    float delx,dely;

public:
    MoveCommand(GraphicsObject* o, float delx, float dely);
    ~MoveCommand(){};

    void execute() override;
    void undo() override;
};