#pragma once
#include <GLFW/glfw3.h>
#include <unordered_map>

class Input
{
public:
	static void initialize(GLFWwindow* window);
	// Was a key pressed but not held
	static bool isKeyPressed(int key);
	// Is key held down
	static bool isKeyDown(int key);
	static void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);

private:
	static std::unordered_map<int, bool> keyStates_;
};
