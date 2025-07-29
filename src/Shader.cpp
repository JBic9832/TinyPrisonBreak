#include "Shader.hpp"
#include "glad/glad.h"
#include "TextFileReader.hpp"

#include <iostream>
#include <fstream>
#include <glm/gtc/type_ptr.hpp>

bool ShaderCompiledSuccessfully(unsigned int& shader)
{
	int success;
	char infoLog[512];
	glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
	if(!success)
	{
		glGetShaderInfoLog(shader, 512, NULL, infoLog);
		std::cout << "FAILED TO COMPILE SHADER:\n\t" << infoLog << std::endl;
		return false;
	}

	return true;
}

Shader::Shader(const std::string& vertexShaderPath, const std::string& fragmentShaderPath)
{
	TextFileReader vertShaderFile(vertexShaderPath);
	TextFileReader fragmentShaderFile(fragmentShaderPath);

	std::string vertexShaderCode = vertShaderFile.GetFileContents();
	std::string fragmentShaderCode = fragmentShaderFile.GetFileContents();
	const char* fragCodeCharPtr = fragmentShaderCode.c_str();
	const char* vertCodeCharPtr = vertexShaderCode.c_str();

	shaderProgram_ = glCreateProgram();

	unsigned int fragmentShader, vertexShader;

	if (vertexShaderCode.empty() || fragmentShaderCode.empty()) {
		std::cerr << "One or more of the shader sources is empty! Aborting shader compilation.\n";
		return;
	}

	vertexShader = glCreateShader(GL_VERTEX_SHADER);
	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

	glShaderSource(vertexShader, 1, &vertCodeCharPtr, NULL);
	glShaderSource(fragmentShader, 1, &fragCodeCharPtr, NULL);

	glCompileShader(vertexShader);
	bool vsCompileSuccess = ShaderCompiledSuccessfully(vertexShader);
	if(!vsCompileSuccess)
		std::cout << "FAILED TO COMPILE VERTEX SHADER:\n\t";

	glCompileShader(fragmentShader);
	bool fsCompileSuccess = ShaderCompiledSuccessfully(fragmentShader);
	if(!fsCompileSuccess)
		std::cout << "FAILED TO COMPILE FRAGMENT SHADER:\n\t";

	glAttachShader(shaderProgram_, vertexShader);
	glAttachShader(shaderProgram_, fragmentShader);

	glLinkProgram(shaderProgram_);

	int success;
	char infoLog[512];
	glGetProgramiv(shaderProgram_, GL_LINK_STATUS, &success);
	if(!success)
	{
		glGetProgramInfoLog(shaderProgram_, 512, NULL, infoLog);
		std::cout << "FAILED TO LINK SHADER:\n\t" << infoLog << std::endl;
	}

	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
}

void Shader::Bind() const
{
	glUseProgram(shaderProgram_);
}

void Shader::SetUniformMat4f(const std::string& uniformName, const glm::mat4& matrix) const
{
	int loc = GetUniformLocation(uniformName);
	glUniformMatrix4fv(loc, 1, GL_FALSE, glm::value_ptr(matrix));
}

int Shader::GetUniformLocation(const std::string& uniformName) const
{
	return glGetUniformLocation(shaderProgram_, uniformName.c_str());
}
