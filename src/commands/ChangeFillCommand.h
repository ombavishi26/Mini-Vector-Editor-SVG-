#pragma once
#include "Command.h"

class ChangeFillCommand : public Command {
private:
    GraphicsObject* object;
    std::string oldFill, newFill;

public:
    ChangeFillCommand(GraphicsObject* object, std::string oldFill, std::string newFill);
    ~ChangeFillCommand(){};

    void execute() override;
    void undo() override;
};