#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <string>

#include "../Buffers/VertexBuffer.h"

class Window {
public:
	Window(int width = 640, int height = 480);
	virtual ~Window();

	bool Initialized();
	bool ShouldClose();
	

	void Update();
	std::string GetId();


	Window(const Window& other) = delete;
	Window& operator = (const Window& other) = delete;
	Window(Window&& other) = delete;
	Window& operator =(Window&& other) = delete;

protected:
	VertexBuffer* dynamicVertexBuffer;

private:
	GLFWwindow* glfwWindow = 0;

	std::string id;
	int width;
	int height;
	bool initialized = false;


	void Initialize();

	virtual void UpdateContent() = 0;
};