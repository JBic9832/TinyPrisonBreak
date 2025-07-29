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
	TexturedRect(const std::string& texturePath, Shader shader);
	void Draw(int x, int y, glm::mat4 proj, glm::mat4 view);
	glm::mat4 GetProjectionMatrix() const;

private:
	VertexArray vao_;
	VertexBuffer vbo_;
	unsigned int textureId_;
	Shader shader_;
	glm::mat4 modelMatrix_;
};
