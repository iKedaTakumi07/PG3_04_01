#include "StageScene.h"
#include "Novice.h"

void StageScene::Initialize()
{

    player_.Pos.X = 300.0f;
    player_.Pos.Y = 600.0f;
    player_.Radius = 30.0f;
    player_.Speed.X = 5.0f;
    player_.Speed.Y = 5.0f;
    player_.coolTime = 10;

    for (int i = 0; i < 8; i++) {
        playerBullet_[i].Pos.X = 0.0f;
        playerBullet_[i].Pos.Y = -100.0f;
        playerBullet_[i].Speed = 5.0f;
        playerBullet_[i].Radius = 5.0f;
        playerBullet_[i].isBulletShot = false;
        playerBullet_[i].isHit = false;
    }

    enemy_.isAilve = true;
    enemy_.Pos = { 100.0f, 100.0f };
    enemy_.Radius = 20.0f;
    enemy_.Speed = { 5.0f, 0.0f };
    enemy_.isHit = false;
}

void StageScene::Update(char* keys, char* preKeys)
{
    if (preKeys[DIK_SPACE] == 0 && keys[DIK_SPACE]) {

        sceneNo = clear;
    }

    enemy_.Pos.X += enemy_.Speed.X;

    if (enemy_.Pos.X <= 50.0f || enemy_.Pos.X >= 1150.0f) {
        enemy_.Speed.X *= -1.0f;
    }

    // Sキーを押したなら下に移動する
    if (keys[DIK_S]) {
        player_.Pos.Y += player_.Speed.Y;
    }

    // Wキーを押したなら上に移動する
    if (keys[DIK_W]) {
        player_.Pos.Y -= player_.Speed.Y;
    }

    // Aキーを押したなら左に移動する
    if (keys[DIK_A]) {
        player_.Pos.X -= player_.Speed.X;
    }

    // Dキーを押したなら右に移動する
    if (keys[DIK_D]) {
        player_.Pos.X += player_.Speed.X;
    }

    // spaceを押したなら
    if (keys[DIK_LSHIFT]) {
        // クールタイムの値が0なら
        if (player_.coolTime <= 0) {
            for (int i = 0; i < 8; i++) {
                // 弾が撃たれていないなら撃つ
                if (!playerBullet_[i].isBulletShot) {

                    playerBullet_[i].isBulletShot = true;

                    // 自機のいる場所に移動させる
                    playerBullet_[i].Pos.X = player_.Pos.X;
                    playerBullet_[i].Pos.Y = player_.Pos.Y;

                    // クールタイムをリセットする
                    player_.coolTime = 10;

                    break;
                }
            }
        }
    }

    // クールタイムが0でないなら値を1つ減らす
    if (player_.coolTime != 0) {
        player_.coolTime--;
    }

    for (int i = 0; i < 8; i++) {
        // 弾を撃っているなら移動させる
        if (playerBullet_[i].isBulletShot) {
            playerBullet_[i].Pos.Y -= playerBullet_[i].Speed;
        }

        // 画面外に出たらフラグを戻す
        if (playerBullet_[i].Pos.Y + playerBullet_[i].Radius <= 0.0f) {
            playerBullet_[i].isBulletShot = false;

            // 座標を元に戻す
            playerBullet_[i].Pos.Y = -100.0f;
        }

        if (enemy_.Pos.X - enemy_.Radius < playerBullet_[i].Pos.X + playerBullet_[i].Radius && playerBullet_[i].Pos.X - playerBullet_[i].Radius < enemy_.Pos.X + enemy_.Radius) {
            if (enemy_.Pos.Y - enemy_.Radius < playerBullet_[i].Pos.Y + playerBullet_[i].Radius && playerBullet_[i].Pos.Y - playerBullet_[i].Radius < enemy_.Pos.Y + enemy_.Radius) {
                playerBullet_[i].isBulletShot = false;
                playerBullet_[i].Pos.Y = -100.0f;
                enemy_.isAilve = false;
            }
        }
    }

    if (!enemy_.isAilve) {
        timer--;
        if (timer <= 0) {
            timer = 60;
            enemy_.isAilve = true;
        }
    }
}

void StageScene::Draw()
{
    // 弾
    for (int i = 0; i < 8; i++) {
        if (playerBullet_[i].isBulletShot) {
            Novice::DrawTriangle(static_cast<int>(playerBullet_[i].Pos.X), static_cast<int>(playerBullet_[i].Pos.Y - 5), static_cast<int>(playerBullet_[i].Pos.X + 5), static_cast<int>(playerBullet_[i].Pos.Y + 5), static_cast<int>(playerBullet_[i].Pos.X - 5), static_cast<int>(playerBullet_[i].Pos.Y + 5), 0x2266FFFF, kFillModeSolid);
        }
    }

    // 自機
    Novice::DrawEllipse(static_cast<int>(player_.Pos.X), static_cast<int>(player_.Pos.Y), static_cast<int>(player_.Radius), static_cast<int>(player_.Radius), 0.0f, 0xFFFFFFFF, kFillModeSolid);

    if (enemy_.isAilve) {
        Novice::DrawEllipse((int)enemy_.Pos.X, (int)enemy_.Pos.Y, static_cast<int>(enemy_.Radius), static_cast<int>(enemy_.Radius), 0.0f, 0x00FFFFFF, kFillModeSolid);
    }

    Novice::ScreenPrintf(0, 0, "Curernt Scene : Stage");
    Novice::ScreenPrintf(0, 30, "Push Space : Next Scene");
    Novice::ScreenPrintf(0, 60, "Push LSHIFT : shot");
}
