#pragma once
#include <string>
#include "VertexArray.hpp"
#include "VertexBuffer.hpp"
#include "Shader.hpp"

class TexturedRect
{
public:
	TexturedRect(const std::string& texturePath, Shader shader);
	void Draw(int x, int y) const;

private:
	VertexArray vao_;
	VertexBuffer vbo_;
	unsigned int textureId_;
	Shader shader_;

};
