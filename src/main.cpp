#include <cstdlib>
#include <stdexcept>
#include <iostream>
#include <string> // For better error messages

#include "FirstApp.hpp"

int main()
{
    try
    {
        NeonEngine::FirstApp app;
        app.run();
    }
    catch (const std::exception &e)
    {
        std::cerr << "An application error occurred: " << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    std::cout << "Application finished successfully." << std::endl;
    return EXIT_SUCCESS;
}