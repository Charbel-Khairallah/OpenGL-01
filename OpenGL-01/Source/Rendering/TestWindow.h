#pragma once

#include "Window.h"
#include "../Shapes/Triangle.h"

class TestWindow : public Window {
public:
	TestWindow();
	TestWindow(int width, int height);

private:
	Triangle testTriangle;

	void UpdateContent();
};