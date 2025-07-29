#pragma once
#include <glad/glad.h>

#include <vector>

class VertexBuffer
{
public:
	VertexBuffer();
	void FillBufferData(std::vector<float> data, const unsigned int usage);
	void Bind() const;
	void EnableVertexAttribArray(unsigned int index, int size, unsigned int type, bool normalized, int stride, const void* offset) const;

private:
	unsigned int rendererId_;
};
