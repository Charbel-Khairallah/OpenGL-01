#pragma once

#include <unordered_map>
#include <string>

#include "Window.h"


class WindowManager {
public:
	static void AddWindow(std::string id, Window* window);
	static void RemoveWindow(std::string id);

	static bool IsEmpty();
	static void Update();
	static void Terminate();
	static int Initialize();

private:
	static std::unordered_map<std::string, Window*> activeWindows;
};