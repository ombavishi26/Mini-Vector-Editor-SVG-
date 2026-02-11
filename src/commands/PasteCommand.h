#pragma once
#include "Command.h"

class PasteCommand : public Command{
private:
    std::vector<GraphicsObject*>& objects;
    GraphicsObject* object;

public:
    PasteCommand(std::vector<GraphicsObject*>& objects, GraphicsObject* object);
    ~PasteCommand(){};

    void execute() override;
    void undo() override;
};
