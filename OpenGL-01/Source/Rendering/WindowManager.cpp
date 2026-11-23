#include <iostream>

#include "WindowManager.h"


std::unordered_map<std::string, Window*> WindowManager::activeWindows;
std::vector<std::string> WindowManager::windowsIdToRemove;
std::vector<Window*> WindowManager::windowsToAdd;


void WindowManager::AddWindow(Window* window) {
	WindowManager::windowsToAdd.push_back(window);
}

void WindowManager::RemoveWindow(std::string id) {
	WindowManager::windowsIdToRemove.push_back(id);
}



bool WindowManager::IsEmpty() {
	return (WindowManager::activeWindows.size() + WindowManager::windowsToAdd.size() + WindowManager::windowsIdToRemove.size()) == 0;
}

void WindowManager::Update() {
	for (int i = 0; i < WindowManager::windowsToAdd.size(); i++) {
		WindowManager::activeWindows.insert({ WindowManager::windowsToAdd[i]->GetId(), WindowManager::windowsToAdd[i] });
	}
	WindowManager::windowsToAdd.clear();

	for (int i = 0; i < WindowManager::windowsIdToRemove.size(); i++) {
		if (activeWindows.find(WindowManager::windowsIdToRemove[i]) != activeWindows.end()) activeWindows.erase(WindowManager::windowsIdToRemove[i]);
	}
	WindowManager::windowsIdToRemove.clear();

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