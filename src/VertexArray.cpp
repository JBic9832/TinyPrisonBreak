#include "VertexArray.hpp"

VertexArray::VertexArray()
{
	glGenVertexArrays(1, &rendererId_);
}

void VertexArray::Bind() const
{
	glBindVertexArray(rendererId_);
}
