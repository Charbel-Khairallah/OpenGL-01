#include <iostream>

#include "Window.h"
#include "WindowManager.h"
#include "../Helpers/UUID.h"


Window::Window(int width, int height) {
	this->width = width;
	this->height = height;

	this->id = UUID::NewUUID();

	Initialize();

	if (Initialized()) WindowManager::AddWindow(this->id, this);
	else delete this;
}

Window::~Window() {
	WindowManager::RemoveWindow(this->id);
	glfwDestroyWindow(glfwWindow);
}

void Window::Initialize() {
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
	glfwMakeContextCurrent(Window::glfwWindow);
	glClear(GL_COLOR_BUFFER_BIT);

	UpdateContent();

	glfwSwapBuffers(glfwWindow);
}

std::string Window::GetId() {
	return this->id;
}