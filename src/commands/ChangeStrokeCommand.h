#pragma once
#include "Command.h"

class ChangeStrokeCommand : public Command{
private:
    GraphicsObject* object;
    std::string oldStroke, newStroke;

public:
    ChangeStrokeCommand(GraphicsObject* object, const std::string& oldStroke, const std::string& newStroke);
    ~ChangeStrokeCommand(){};

    void execute() override;
    void undo() override;
};