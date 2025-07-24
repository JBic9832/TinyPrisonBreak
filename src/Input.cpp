#include "Input.hpp"
#include "GLFW/glfw3.h"

std::unordered_map<int, bool> Input::keyStates_;

void Input::initialize(GLFWwindow* window)
{
	glfwSetKeyCallback(window, Input::keyCallback);
}

bool Input::isKeyPressed(int key)
{
	bool result = keyStates_[key];
	keyStates_[key] = false;
	return result;
}

bool Input::isKeyDown(int key)
{
	return keyStates_[key];
}

void Input::keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if(action == GLFW_PRESS) 
	{
		keyStates_[key] = true;
	} else if(action == GLFW_RELEASE)
	{
		keyStates_[key] = false;
	}

}
