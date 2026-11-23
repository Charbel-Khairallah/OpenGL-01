#pragma once

class Vertex {
public:
	Vertex(float x, float y);

	float GetX();
	float GetY();
private:
	float x;
	float y;
};