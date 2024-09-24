#include <GLFW/glfw3.h>
#include <string>

namespace NEW
{
    class NEWindow
    {
        public:
        NEWindow(int w, int h, std::string windowTitle);
        ~NEWindow();


        private:
        const int WIDTH;
        const int HEIGHT;
        const std::string TITLE;
        void initWindow();
        GLFWwindow *window;

    };
} // namespace NEW "Neon Engine Window"

