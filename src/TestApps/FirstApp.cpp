// FirstApp.cpp
#include "FirstApp.hpp"

void NeonEngine::FirstApp::run()
{
    while (!firstWindow.shouldClose())
    {
        glfwPollEvents();
    }
}