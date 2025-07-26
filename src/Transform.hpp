#pragma once
#include <glm/glm.hpp>
#include <glm/gtc/quaternion.hpp>

class Transform
{
public:
	Transform();

	void SetPosition(float x, float y);
	void SetScale(float x, float y);

	glm::mat4 GetModelMatrix() const;
	void SetModelMatrix(glm::vec2 position, glm::vec2 scale);

	//TODO:
	//Implement: Translate (similar to set position but give a delta not an exact position)

private:
	glm::vec2 position_;
	glm::vec2 scale_;
	glm::mat4 modelMatrix_ = glm::mat4(1.0f);
};
