#pragma once

class VertexBuffer {
public:
	VertexBuffer();

	void Draw();
	void Add(float* verticies, int count);
	int GetVertexCount();

private:
	const int INITIAL_CAPACITY = 16;

	unsigned int bufferId;
	float* bufferArray;

	int currentCount = 0;
	int maxCount = INITIAL_CAPACITY;
};