// std
#include <cstdlib>
#include <stdexcept>
#include <iostream>

#include "src/FirstApp.hpp"

int main()
{
    NeonEngine::FirstApp app{};

    try
    {
        app.run();
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}