#pragma once
#include "IScene.h"
#include "InputHandler.h"
#include "Player.h"

class StageScene : public IScene {
public:
    StageScene();

    void Initialize() override;
    void Update(char* keys, char* preKeys) override;
    void Draw() override;

private:
    InputHandler* inputHandler_ = nullptr;
    Command* iCommand_ = nullptr;
    Player* player_;
};