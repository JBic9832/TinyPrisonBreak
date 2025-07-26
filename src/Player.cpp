#include "Player.hpp"

Player::Player()
{ 
	transform_.SetPosition(0.0f, 0.0f);

}

Player::Player(int posX, int posY)
{
	transform_.SetPosition(posX, posY);
}

void Player::Draw() const
{

}
