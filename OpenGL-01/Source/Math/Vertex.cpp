#include "Vertex.h"

Vertex::Vertex(float x, float y) {
	this->x = x;
	this->y = y;
}

float Vertex::GetX() {
	return this->x;
}

float Vertex::GetY() {
	return this->y;
}