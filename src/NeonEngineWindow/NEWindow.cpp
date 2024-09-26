#include "NEWindow.hpp"

#include <iostream>
#include <stdexcept>

namespace NeonEngine
{

    NEWindow::NEWindow(int w, int h, const std::string &title) : width{w}, height{h}, windowTitle{title}
    {
        initWindow();
    }

    NEWindow::~NEWindow()
    {
        glfwDestroyWindow(window);
        glfwTerminate();
        std::cout << "Deconstructor called" << std::endl;
    }

    void NEWindow::initWindow()
    {
        if (!glfwInit())
        {
            throw std::runtime_error("Failed to initialize GLFW");
        }

        glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
        glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

        window = glfwCreateWindow(width, height, windowTitle.c_str(), nullptr, nullptr);
        if (!window)
        {
            glfwTerminate();
            throw std::runtime_error("Failed to create window");
        }
    }

    void NEWindow::createWindowSurface(VkInstance instance, VkSurfaceKHR *surface) const
    {
        if (glfwCreateWindowSurface(instance, window, nullptr, surface) != VK_SUCCESS)
        {
            throw std::runtime_error("Failed to create (Vulkan) window surface");
        }
    }

} // namespace NeonEngine