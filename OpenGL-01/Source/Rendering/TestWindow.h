#pragma once

#include "Window.h"

class TestWindow : public Window {
public:
	TestWindow();
	TestWindow(int width, int height);

private:
	void UpdateContent();
};