#include "Command.h"
#include "Player.h"

Command::~Command()
{
}

void MoveRightCommand::Exec(Player& player)
{
    player.MoveRight();
}

void MoveLeftCommand::Exec(Player& player)
{
    player.MoveLeft();
}
