#include "GameManager.h"
#include <Novice.h>

GameManager::GameManager()
{
    sceneArr_[title] = std::make_unique<TitleScene>();
    sceneArr_[stage] = std::make_unique<StageScene>();
    sceneArr_[clear] = std::make_unique<ClearScene>();

    currentSceneNo_ = title;


}

GameManager::~GameManager()
{
}

int GameManager::Run()
{
    while (Novice::ProcessMessage() == 0) {
        Novice::BeginFrame();

        // シーンのチェック
        prevSceneNo_ = currentSceneNo_;
        currentSceneNo_ = sceneArr_[currentSceneNo_]->GetSceneNo();

        if (prevSceneNo_ != currentSceneNo_) {
            sceneArr_[currentSceneNo_]->Initialize();
        }

        // キー入力を受け取る
        memcpy(preKeys, keys, 256);
        Novice::GetHitKeyStateAll(keys);

        sceneArr_[currentSceneNo_]->Update(keys, preKeys);
        sceneArr_[currentSceneNo_]->Draw();
        Novice::EndFrame();

        if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
            break;
        }
    }
    return 0;
}
