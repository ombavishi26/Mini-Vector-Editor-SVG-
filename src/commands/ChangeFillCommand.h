#pragma once
#include "Command.h"

class ChangeFillCommand : public Command {
private:
    GraphicsObject* object;
    std::string oldFill, newFill;

public:
    ChangeFillCommand(GraphicsObject* object,const std::string& oldFill,const std::string& newFill);
    ~ChangeFillCommand(){};

    void execute() override;
    void undo() override;
};