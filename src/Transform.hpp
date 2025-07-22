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
	glm::vec3 position_;
	glm::quat rotation_;
	glm::vec3 scale_;

};
