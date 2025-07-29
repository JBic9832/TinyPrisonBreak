#include "TexturedRect.hpp"
#include <vector>
#include <glm/gtc/matrix_transform.hpp>
#include "ResourceManager.hpp"

//TODO
//	TexturedRect constructor takes in std::string& to look up shader.
//	Shader creation is handled by a resource manager which holds a static
//	map of all shader programs

TexturedRect::TexturedRect(const std::string& textureFilePath, const std::string& shader, float width, float height)
	: width_ { width }
	, height_ { height }
{
	shader_ = ResourceManager::GetShader(shader);

	modelMatrix_ = glm::mat4(1.0f);
	std::vector<float> verts = {
		// First triangle
	   -1.0f, -1.0f, 0.0f,  // Bottom-left
		1.0f, -1.0f, 0.0f,  // Bottom-right
		1.0f,  1.0f, 0.0f,  // Top-right

		// Second triangle
		-1.0f, -1.0f, 0.0f,  // Bottom-left
		1.0f,  1.0f, 0.0f,  // Top-right
		-1.0f,  1.0f, 0.0f   // Top-left
	};

	vao_.Bind();
	vbo_.Bind();
	vbo_.FillBufferData(verts, GL_STATIC_DRAW);
	vbo_.EnableVertexAttribArray(0, 3, GL_FLOAT, false, 0, (void*)0);
}

void TexturedRect::Draw(float x, float y, glm::mat4 proj, glm::mat4 view)
{
	modelMatrix_ = glm::mat4(1.0f);
	modelMatrix_ = glm::translate(modelMatrix_, glm::vec3(x, y, 0.0f));
	modelMatrix_ = glm::scale(modelMatrix_, glm::vec3(width_, height_, 1.0f));
	vao_.Bind();
	shader_.Bind();
	shader_.SetUniformMat4f("model", modelMatrix_);
	shader_.SetUniformMat4f("view", view);
	shader_.SetUniformMat4f("projection", proj);
	glDrawArrays(GL_TRIANGLES, 0, 6);
}

// Not needed
glm::mat4 TexturedRect::GetProjectionMatrix() const 
{
	return modelMatrix_;
}
