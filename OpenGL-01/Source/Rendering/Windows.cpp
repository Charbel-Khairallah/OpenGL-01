#include "Windows.h"


std::unordered_map<std::string, Window*> Windows::activeWindows;


void Windows::AddWindow(std::string id, Window* window) {
	activeWindows.insert({ id, window });
}

void Windows::RemoveWindow(std::string id) {
	activeWindows.erase(id);
}



bool Windows::IsEmpty() {
	return Windows::activeWindows.size() == 0;
}

void Windows::Update() {
	std::vector<std::string> toDelete;
	for (std::unordered_map<std::string, Window*>::iterator it = Windows::activeWindows.begin(); it != Windows::activeWindows.end(); it++) {
		it->second->Update();
		if (it->second->SHOULD_CLOSE) toDelete.push_back(it->first);
	}

	for (int i = 0; i < toDelete.size(); i++) {
		delete Windows::activeWindows[toDelete[i]];
		Windows::activeWindows.erase(toDelete[i]);
	}
}

void Windows::Terminate() {
	glfwTerminate();
}