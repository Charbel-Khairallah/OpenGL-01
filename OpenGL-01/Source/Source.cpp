#include "Rendering/Windows.h"
#include "Rendering/TestWindow.h"

int main(void)
{
    TestWindow* testWindow = new TestWindow();

    while (!Windows::IS_EMPTY) {
        Windows::Update();
    }

    Windows::Terminate();
    return 0;
}