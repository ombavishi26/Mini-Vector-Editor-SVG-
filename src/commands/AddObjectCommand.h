#pragma once
#include "Command.h"

class AddObjectCommand : public Command{
private:
    std::vector<GraphicsObject*>& objects;
    GraphicsObject* object;

public:
    AddObjectCommand(std::vector<GraphicsObject*>& objects, GraphicsObject* object);
    ~AddObjectCommand() override {}
    
    void execute() override;
    void undo() override;
};