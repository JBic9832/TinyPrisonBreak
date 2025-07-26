#include "Transform.hpp"

Transform::Transform()
	: position_ { glm::vec3(0.0f) }
	, scale_ { glm::vec3(0.0f) }
{ }

void Transform::SetPosition(float x, float y)
{
	glm::vec2 newPositionVector{x, y};
	position_.x = newPositionVector.x;
	position_.y = newPositionVector.y;
	modelMatrix_ = glm::translate(glm::mat4(1.0f), glm::vec3(newPositionVector, 1.0f));
}

void Transform::SetScale(float x, float y)
{
	glm::vec2 newScaleVector{x, y};
	scale_.x = newScaleVector.x;
	scale_.y = newScaleVector.y;
}

glm::mat4 Transform::GetModelMatrix() const
{
	return modelMatrix_;
}

