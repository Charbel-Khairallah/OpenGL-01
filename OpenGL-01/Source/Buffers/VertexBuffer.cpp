#include <GL/glew.h>

#include "VertexBuffer.h"


VertexBuffer::VertexBuffer() {
	this->bufferArray = new float[this->maxCount];

	glGenBuffers(1, &this->bufferId);
	glBindBuffer(GL_ARRAY_BUFFER, this->bufferId);
	glBufferData(GL_ARRAY_BUFFER, this->maxCount * sizeof(float), this->bufferArray, GL_DYNAMIC_DRAW);
}

void VertexBuffer::Draw() {
	glDrawArrays(GL_TRIANGLES, 0, this->currentCount * 0.5);
}

void VertexBuffer::Add(float* verticies, int count) {
	if ((this->currentCount + count) > this->maxCount) {
		
		// To Do Later, Increase Capacity
		return;
	}

	for (int i = 0; i < count; i++) {
		this->bufferArray[this->currentCount++] = verticies[i];
	}
}

int VertexBuffer::GetVertexCount() {
	return this->currentCount * 0.5;
}