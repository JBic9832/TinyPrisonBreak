#pragma once

#include <glad/glad.h>
#include <string>

class Shader
{
public:
  Shader(const std::string& vertexShaderPath, const std::string& fragmentShaderPath);
  void Bind();

private:
  unsigned int     shaderProgram_;
};
