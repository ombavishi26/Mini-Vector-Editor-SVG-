#pragma once
#include <vector>
#include "../Objects/GraphicsObject.h"

class Command{
public:
    virtual ~Command() = default;

    virtual void execute() = 0;
    virtual void undo() = 0;
};