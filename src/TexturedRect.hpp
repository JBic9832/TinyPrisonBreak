#pragma once
#include <string>
#include <glm/glm.hpp>
#include "VertexArray.hpp"
#include "VertexBuffer.hpp"
#include "Shader.hpp"

class TexturedRect
{
public:
	TexturedRect() {};
	TexturedRect(const std::string& texturePath, const std::string& shader, float width, float height);
	void Draw(float x, float y, glm::mat4 proj, glm::mat4 view);
	glm::mat4 GetProjectionMatrix() const;

private:
	VertexArray vao_;
	VertexBuffer vbo_;
	unsigned int textureId_;
	Shader shader_;
	glm::mat4 modelMatrix_;
	float width_, height_;
};
