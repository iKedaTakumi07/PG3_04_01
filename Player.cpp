#include "Player.h"
#include "Novice.h"

Player::Player()
{
}

void Player::Update()
{
}

void Player::Draw() {
    Novice::DrawBox(pos_.x, pos_.y, 10, 10, 0.0f, 0xFFFFFFFF, kFillModeSolid);
}

void Player::MoveRight()
{
    this->pos_.x += this->speed_.x;
}

void Player::MoveLeft()
{
    this->pos_.x -= this->speed_.x;
}
