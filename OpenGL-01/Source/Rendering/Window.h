#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <string>


#define INITIALIZED Initialized()
#define SHOULD_CLOSE ShouldClose()
#define ID GetId()


class Window {
public:
	Window(int width = 640, int height = 480);
	virtual ~Window();

	bool Initialized();
	bool ShouldClose();
	

	void Update();
	std::string GetId();
private:
	GLFWwindow* glfwWindow = NULL;

	std::string id;
	int width;
	int height;
	bool initialized = false;

	void Initialize();

	virtual void UpdateContent() = NULL;
};