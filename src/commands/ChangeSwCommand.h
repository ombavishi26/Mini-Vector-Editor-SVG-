#pragma once
#include "Command.h"

class ChangeSwCommand : public Command{
private:
    GraphicsObject* object;
    float oldsw,newsw;

public:
    ChangeSwCommand(GraphicsObject* object, const float oldsw, const float newsw);
    ~ChangeSwCommand(){};

    void execute() override;
    void undo() override;
};