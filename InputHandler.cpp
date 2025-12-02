#include "InputHandler.h"

Command* InputHandler::HandleInput()
{
    if (Novice::CheckHitKey(DIK_D)) {
        return pressKeyD_;
    }
    if (Novice::CheckHitKey(DIK_A)) {
        return pressKeyA_;
    }
    return nullptr;
}

void InputHandler::AssignMoveLeftCommand2PressKeyA()
{
    Command* Command = new MoveLeftCommand();
    this->pressKeyA_ = Command;
}

void InputHandler::AssignMoveRightCommand2PressKeyD()
{
    Command* Command = new MoveRightCommand();
    this->pressKeyD_ = Command;
}
