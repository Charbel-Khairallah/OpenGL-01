#include "Rendering/WindowManager.h"
#include "Rendering/TestWindow.h"


int main(void)
{
    if (WindowManager::Initialize() < 0) return -1;

    new TestWindow();
    new TestWindow();


    while (!WindowManager::IsEmpty()) {
        WindowManager::Update();
    }

    WindowManager::Terminate();
    return 0;
}