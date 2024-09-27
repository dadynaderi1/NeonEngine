// FirstApp.cpp
#include "TestApps/FirstApp.hpp"

void NeonEngine::FirstApp::run()
{
    while (!firstWindow.shouldClose())
    {
        glfwPollEvents();
    }
}