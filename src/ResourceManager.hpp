#pragma once

#include <map>
#include <string>

#include "Shader.hpp"

class ResourceManager
{
public:
	static std::map<std::string, Shader> Shaders;

	static Shader LoadShader(const std::string& vShaderFile, const std::string& fShaderFile, const std::string& shaderName);
	static Shader GetShader(const std::string& shaderName);

	static void Clear();

private:
	ResourceManager();
	~ResourceManager();
};
