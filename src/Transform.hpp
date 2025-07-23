#pragma once
#include <glm/glm.hpp>
#include <glm/gtc/quaternion.hpp>

class Transform
{
public:
	Transform();

	void SetPosition(float x, float y, float z);
	void SetScale(float x, float y, float z);

	//TODO:
	//Implement: Translate (similar to set position but give a delta not an exact position)

private:
	glm::vec2 position_;
	glm::vec2 scale_;

};
