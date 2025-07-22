#pragma once

#include <glad/glad.h>

class VertexArray
{
public:
	VertexArray();

	void Bind() const;

private:
	unsigned int rendererId_;

};
