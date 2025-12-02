#pragma once
#include "Command.h"
#include "Novice.h"
class InputHandler {
public:
    Command* HandleInput();

    void AssignMoveLeftCommand2PressKeyA();
    void AssignMoveRightCommand2PressKeyD();

private:
    Command* pressKeyD_;
    Command* pressKeyA_;
};
