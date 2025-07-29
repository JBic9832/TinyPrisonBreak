#include "Player.hpp"

Player::Player()
{ 
	transform_.SetPosition(0.0f, 0.0f);
}

Player::Player(int posX, int posY)
	: xPos_ { posX }
	, yPos_ { posY }
{
	shader_ = Shader(RESOURCES_PATH "basicVert.glsl", RESOURCES_PATH "basicFrag.glsl");
	transform_.SetPosition(posX, posY);
	TexturedRect(RESOURCES_PATH "img/Player.png", shader_);
}

void Player::Draw(glm::mat4 proj, glm::mat4 view) 
{
	texturedRect_.Draw(xPos_, yPos_, proj, view);
}
