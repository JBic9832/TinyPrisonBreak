#include "Transform.hpp"

Transform::Transform()
	: position_ { glm::vec3(0.0f) }
	, scale_ { glm::vec3(0.0f) }
{ }

void Transform::SetPosition(float x, float y, float z)
{
	glm::vec3 newPositionVector{x, y, z};
	position_.x = newPositionVector.x;
	position_.y = newPositionVector.y;
	position_.z = newPositionVector.z;
}

void Transform::SetScale(float x, float y, float z)
{
	glm::vec3 newScaleVector{x, y, z};
	scale_.x = newScaleVector.x;
	scale_.y = newScaleVector.y;
	scale_.z = newScaleVector.z;
}
