// FirstApp.cpp
#include "./TestApps/FirstApp.hpp"

void NeonEngine::FirstApp::run()
{
    printWorkingDirectory();
    while (!firstWindow.shouldClose())
    {

        glfwPollEvents();
    }
}