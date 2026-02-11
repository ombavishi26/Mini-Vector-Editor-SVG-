#pragma once
#include "Command.h"

class CutCommand : public Command{
private:
    std::vector<GraphicsObject*>& objects;
    GraphicsObject* object;
    size_t index;

public:
    CutCommand(std::vector<GraphicsObject*>& objects, GraphicsObject* object);
    ~CutCommand(){};

    void execute() override;
    void undo() override;
    
};