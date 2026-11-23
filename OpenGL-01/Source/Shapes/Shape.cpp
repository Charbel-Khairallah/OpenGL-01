#include "Shape.h"

Shape::Shape() {
	
}

Shape::~Shape() {
	if(this->verticies != nullptr) delete[] this->verticies;
}


void Shape::AssignVerticies(std::vector<Vertex> vertexData) {
	if (this->verticies != nullptr) delete[] this->verticies;
	this->verticies = new float[vertexData.size() * 2];
	for (int i = 0; i < vertexData.size(); i++) {
		int j = i / 2;
		if(i % 2 == 0) this->verticies[i] = vertexData[j].GetX();
		else this->verticies[i] = vertexData[j].GetY();
	}

	vertexCount = vertexData.size() * 2;
}

float* Shape::GetVerticies() {
	return this->verticies;
}

int Shape::GetVertexCount() {
	return this->vertexCount;
}

Shape& Shape::operator = (const Shape& other) {
	if (this == &other) return *this;

	this->verticies = nullptr;
	this->vertexCount = other.vertexCount;
	if (this->vertexCount > 0) {
		this->verticies = new float[this->vertexCount];
		for (int i = 0; i < this->vertexCount; i++) this->verticies[i] = other.verticies[i];
	}
}