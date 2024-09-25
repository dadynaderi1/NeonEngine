#pragma once
#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include <string>

namespace NeonEngine
{
    class NeWindow
    {
    public:
        NeWindow(int w, int h, std::string title);
        ~NeWindow();

        NeWindow(const NeWindow &) = delete;
        NeWindow &operator=(const NeWindow &) = delete;

        bool shouldClose() { return glfwWindowShouldClose(window); }

    private:
        const int height;
        const int width;
        void initWindow();

        std::string windowTitle;
        GLFWwindow *window;
    };
} // namespace NeonEngine
