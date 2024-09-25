#include "NEWindow.hpp"
#include "NEWindow.hpp"
namespace NeonEngine
{
    NeWindow::NeWindow(int w, int h, std::string title) : width{w}, height{h}, windowTitle{title}
    {
        initWindow();
    }
    NeWindow::~NeWindow()
    {
        glfwDestroyWindow(window);
        glfwTerminate();
    }

    void NeWindow::initWindow()
    {
        glfwInit();
        glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
        glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

        window = glfwCreateWindow(width, height, windowTitle.c_str(), nullptr, nullptr);
    }
} // namespace NeonEngine
