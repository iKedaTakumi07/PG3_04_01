#include "StageScene.h"
#include "Novice.h"

StageScene::StageScene()
{
}

void StageScene::Initialize()
{
    inputHandler_ = new InputHandler();

    inputHandler_->AssignMoveRightCommand2PressKeyD();
    inputHandler_->AssignMoveLeftCommand2PressKeyA();

    player_ = new Player();
}

void StageScene::Update(char* keys, char* preKeys)
{
    keys;
    preKeys;

    iCommand_ = inputHandler_->HandleInput();

    if (this->iCommand_) {
        iCommand_->Exec(*player_);
    }

    player_->Update();
}

void StageScene::Draw()
{
    Novice::ScreenPrintf(0, 0, "Curernt Scene : Stage");
    Novice::ScreenPrintf(0, 30, "Push Space : Next Scene");

    player_->Draw();
}
