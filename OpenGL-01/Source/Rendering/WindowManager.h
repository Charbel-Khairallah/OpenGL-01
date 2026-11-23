#pragma once

#include <unordered_map>
#include <vector>
#include <string>

#include "Window.h"


class WindowManager {
public:
	static void AddWindow(Window* window);
	static void RemoveWindow(std::string id);

	static bool IsEmpty();
	static void Update();
	static void Terminate();
	static int Initialize();

private:
	static std::unordered_map<std::string, Window*> activeWindows;

	static std::vector<std::string> windowsIdToRemove;
	static std::vector<Window*> windowsToAdd;
};