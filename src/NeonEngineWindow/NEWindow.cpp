#define GLFW_INCLUDE_VULKAN
#include "NEWindow.hpp"
#include <cstdio>

namespace NEW{
    NEWindow::NEWindow(int w, int h , std::string windowTitle): WIDTH{w},HEIGHT{h},TITLE{windowTitle}
    {
        initWindow();
    }
    NEWindow::~NEWindow()
    {
        glfwDestroyWindow(window);
        glfwTerminate();
    };

    void NEWindow::initWindow()
    {
        if(glfwInit() == GLFW_TRUE)
        {
            glfwWindowHint(GLFW_CLIENT_API,GLFW_NO_API);
            glfwWindowHint(GLFW_RESIZABLE,GLFW_FALSE);
            printf("GLFW INITIALIZED SUCCESSFULLY!");
            window = glfwCreateWindow(WIDTH,HEIGHT,TITLE.c_str(),nullptr,nullptr);
        }
        else
        {
            printf("GLFW not initialized...");
            // implementing spdlog and proper logging
        }
        
    }
}