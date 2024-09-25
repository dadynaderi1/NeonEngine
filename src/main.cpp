// std
#include <cstdlib>
#include <stdexcept>
#include <iostream>

#include "FirstApp.hpp"

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
    std::cout << "everything is fine" << std::endl;
    return EXIT_SUCCESS;
}