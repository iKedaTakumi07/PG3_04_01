#pragma once
class Player {
private:
    typedef struct Vector2 {
        int x;
        int y;
    } Vector2;

    Vector2 pos_ = { 10, 10 };
    Vector2 speed_ = { 1, 1 };

public:
    Player();

    void Init();
    void Update();
    void Draw();

    // メンバ関数
    void MoveRight();
    void MoveLeft();
};
