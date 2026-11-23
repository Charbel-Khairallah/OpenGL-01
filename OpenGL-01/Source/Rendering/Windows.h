#pragma once

#include <unordered_map>
#include <string>

#include "Window.h"

#define IS_EMPTY IsEmpty()


class Windows {
public:
	static void AddWindow(std::string id, Window* window);
	static void RemoveWindow(std::string id);

	static bool IsEmpty();
	static void Update();
	static void Terminate();

private:
	static std::unordered_map<std::string, Window*> activeWindows;
};