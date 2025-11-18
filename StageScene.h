#pragma once
#include "IScene.h"
class StageScene : public IScene {
public:
    typedef struct Vecter2 {
        float X;
        float Y;
    } Vecter2;

    typedef struct Player {
        Vecter2 Pos;
        Vecter2 Speed;
        float Radius;
        int coolTime;
    } Player;

    typedef struct Bullet {
        Vecter2 Pos;
        float Speed;
        float Radius;
        int isBulletShot;
        bool isHit;
    } Buleet;

    typedef struct Enemy {
        Vecter2 Pos;
        Vecter2 Speed;
        float Radius;
        bool isAilve;
        bool isHit;
    } Enemy;

    void Initialize() override;
    void Update(char* keys, char* preKeys) override;
    void Draw() override;

private:
    Player player_;

    Bullet playerBullet_[8];

    Enemy enemy_;

    int timer = 60;
};