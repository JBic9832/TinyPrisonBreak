#include "Player.hpp"
#include "Input.hpp"

#include <iostream>

Player::Player()
{ 
}

Player::Player(float posX, float posY, const std::string& shader)
	: xPos_ { posX }
	, yPos_ { posY }
{
	texturedRect_ = TexturedRect("", shader, 50, 50);
}

void Player::Draw(glm::mat4 proj, glm::mat4 view) 
{
	std::cout << "Drawing at: " << xPos_ << ", " << yPos_ << std::endl;
	texturedRect_.Draw(xPos_, yPos_, proj, view);
}

void Player::Update(float deltaTime)
{
	std::cout << "Delta time: " << deltaTime << std::endl;
	if(Input::isKeyDown(GLFW_KEY_W))
	{
		yPos_ -= speed_ * deltaTime;
	}
	if(Input::isKeyDown(GLFW_KEY_S))
	{
		yPos_ += speed_ * deltaTime;
	}
	if(Input::isKeyDown(GLFW_KEY_D))
	{
		xPos_ += speed_ * deltaTime;
	}
	if(Input::isKeyDown(GLFW_KEY_A))
	{
		xPos_ -= speed_ * deltaTime;
	}
}
