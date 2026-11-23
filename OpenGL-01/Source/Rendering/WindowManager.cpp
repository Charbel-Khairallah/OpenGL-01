#include "WindowManager.h"


std::unordered_map<std::string, Window*> WindowManager::activeWindows;


void WindowManager::AddWindow(std::string id, Window* window) {
	activeWindows.insert({ id, window });
}

void WindowManager::RemoveWindow(std::string id) {
	if(activeWindows.find(id) != activeWindows.end()) activeWindows.erase(id);
}



bool WindowManager::IsEmpty() {
	return WindowManager::activeWindows.size() == 0;
}

void WindowManager::Update() {
	glfwPollEvents();


	std::vector<std::string> toDelete;
	for (std::unordered_map<std::string, Window*>::iterator it = WindowManager::activeWindows.begin(); it != WindowManager::activeWindows.end(); it++) {
		it->second->Update();
		if (it->second->ShouldClose()) toDelete.push_back(it->first);
	}

	for (int i = 0; i < toDelete.size(); i++) {
		delete WindowManager::activeWindows[toDelete[i]];
	}
}

void WindowManager::Terminate() {
	glfwTerminate();
}

int WindowManager::Initialize() {
	if (!glfwInit()) return -1;
}