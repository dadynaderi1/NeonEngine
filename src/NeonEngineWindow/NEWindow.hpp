#pragma once

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include <string>

namespace NeonEngine
{

    /// @brief Represents a window for the application.
    ///
    /// This class provides methods for creating, managing, and interacting with a window.
    class NEWindow
    {
    public:
        /// @brief Constructor.
        ///
        /// Creates a new `NEWindow` object with the specified dimensions and title.
        ///
        /// @param w The width of the window.
        /// @param h The height of the window.
        /// @param title The title of the window.
        NEWindow(int w, int h, const std::string &title);

        /// @brief Destructor.
        ///
        /// Destroys the window and cleans up resources.
        ~NEWindow();

        // Not copyable or movable
        NEWindow(const NEWindow &) = delete;
        NEWindow &operator=(const NEWindow &) = delete;

        /// @brief Checks if the window should be closed.
        ///
        /// @return True if the window should be closed, otherwise false.
        bool shouldClose() const { return glfwWindowShouldClose(window); }

        /// @brief Creates a Vulkan surface associated with the window.
        ///
        /// @param instance The Vulkan instance.
        /// @param surface Pointer to a variable where the created surface handle is stored.
        void createWindowSurface(VkInstance instance, VkSurfaceKHR *surface) const;

    private:
        /// @brief Initializes the GLFW window.
        void initWindow();

        const int height;
        const int width;

        std::string windowTitle;
        GLFWwindow *window;
    };

} // namespace NeonEngine