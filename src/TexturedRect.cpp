#include "TexturedRect.hpp"
#include <vector>

TexturedRect::TexturedRect(const std::string& textureFilePath, Shader shader)
	: shader_ { shader }
{
	std::vector<float> verts = {
		// First Triangle
		-1.0f, -1.0f,  0.0f, 0.0f,  // Bottom-left
		1.0f, -1.0f,  1.0f, 0.0f,  // Bottom-right
		1.0f,  1.0f,  1.0f, 1.0f,  // Top-right

		// Second Triangle
		-1.0f, -1.0f,  0.0f, 0.0f,  // Bottom-left
		1.0f,  1.0f,  1.0f, 1.0f,  // Top-right
		-1.0f,  1.0f,  0.0f, 1.0f   // Top-left
	};

	vao_.Bind();
	vbo_.Bind();
	vbo_.FillBufferData(verts, GL_STATIC_DRAW);
	vbo_.EnableVertexAttribArray(0, verts.size(), GL_FLOAT, false, 0, (void*)0);
}

void TexturedRect::Draw(int x, int y) const {

}
