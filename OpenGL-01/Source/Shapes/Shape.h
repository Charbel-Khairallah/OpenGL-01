#pragma once

#include <vector>

#include "../Math/Vertex.h"

class Shape {
public:
	Shape();
	virtual ~Shape();

	float* GetVerticies();
	int GetVertexCount();

	Shape& operator=(const Shape& other);

protected:
	float* verticies = nullptr;

	void AssignVerticies(std::vector<Vertex> vertexData);

private:
	int vertexCount = 0;

};