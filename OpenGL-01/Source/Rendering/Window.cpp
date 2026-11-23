#include <iostream>

#include "Window.h"
#include "Windows.h"


Window::Window(int width, int height) {
	this->width = width;
	this->height = height;

	// To Be Changed Later For A Unique GUID / UUID
	this->id = "Test";

	Windows::AddWindow(this->id, this);

	Initialize();
}

Window::~Window() {
	
}

void Window::Initialize() {
	if (!glfwInit()) return;

	Window::glfwWindow = glfwCreateWindow(width, height, "Window", NULL, NULL);
	if (!Window::glfwWindow)
	{
		glfwTerminate();
		return;
	}


	glfwMakeContextCurrent(Window::glfwWindow);

	if (glewInit() != GLEW_OK) {
		std::cout << "Glew Init Failed" << std::endl;
	}

	this->initialized = true;
}

bool Window::Initialized() {
	return this->initialized;
}

bool Window::ShouldClose() {
	return glfwWindowShouldClose(glfwWindow);
}

void Window::Update() {
	/* Render here */
	glClear(GL_COLOR_BUFFER_BIT);

	UpdateContent();

	/* Swap front and back buffers */
	glfwSwapBuffers(glfwWindow);

	/* Poll for and process events */
	glfwPollEvents();
}

std::string Window::GetId() {
	return this->id;
}