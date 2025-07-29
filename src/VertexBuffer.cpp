#include "VertexBuffer.hpp"

VertexBuffer::VertexBuffer()
{
	glGenBuffers(1, &rendererId_);
}

void VertexBuffer::FillBufferData(std::vector<float> data, const unsigned int usage)
{
	glBindBuffer(GL_ARRAY_BUFFER, rendererId_);
	glBufferData(GL_ARRAY_BUFFER, data.size() * sizeof(float), data.data(), usage);
}
void VertexBuffer::Bind() const
{
	glBindBuffer(GL_ARRAY_BUFFER, rendererId_);
}
void VertexBuffer::EnableVertexAttribArray(unsigned int index, int size, unsigned int type, bool normalized, int stride, const void* offset) const
{
	glEnableVertexAttribArray(index);
	glVertexAttribPointer(index, size, type, normalized, stride, offset);
}
