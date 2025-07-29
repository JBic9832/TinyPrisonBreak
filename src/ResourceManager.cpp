#include "ResourceManager.hpp"

std::map<std::string, Shader> ResourceManager::Shaders;

Shader ResourceManager::LoadShader(const std::string& vShaderFile, const std::string& fShaderFile, const std::string& shaderName)
{
	Shaders[shaderName] = Shader(vShaderFile, fShaderFile);
	return Shaders[shaderName];
}

Shader ResourceManager::GetShader(const std::string& shaderName) 
{
	return Shaders[shaderName];
}
