#pragma once
#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include <string>

namespace NeonEngine
{
    class NEWindow
    {
    public:
        NEWindow(int w, int h, std::string title);
        ~NEWindow();

        NEWindow(const NEWindow &) = delete;
        NEWindow &operator=(const NEWindow &) = delete;

        bool shouldClose() { return glfwWindowShouldClose(window); }

        void createWindowSurface(VkInstance instance, VkSurfaceKHR *surface);

    private:
        const int height;
        const int width;
        void initWindow();

        std::string windowTitle;
        GLFWwindow *window;
    };
} // namespace NeonEngine
