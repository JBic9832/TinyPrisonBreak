#pragma once

#include <glad/glad.h>
#include <string>
#include <glm/glm.hpp>

class Shader
{
public:
	Shader() {};
	Shader(const std::string& vertexShaderPath, const std::string& fragmentShaderPath);
	void Bind() const;
	void SetUniformMat4f(const std::string& uniformName, const glm::mat4& matrix) const;
	int GetUniformLocation(const std::string& uniformName) const;

private:
	unsigned int     shaderProgram_;
};
