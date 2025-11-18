#include "ClearScene.h"
#include <Novice.h>

void ClearScene::Initialize()
{
}

void ClearScene::Update(char* keys, char* preKeys)
{
    if (preKeys[DIK_SPACE] == 0 && keys[DIK_SPACE] ) {

        sceneNo = title;
    }
}

void ClearScene::Draw()
{
    Novice::ScreenPrintf(0, 0, "Curernt Scene : clear");
    Novice::ScreenPrintf(0, 30, "Push Space : Next Scene");
}
