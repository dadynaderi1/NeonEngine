#pragma once

#include <iostream>
#include <filesystem>
#include "NeonEngineWindow/NEWindow.hpp"
#include "NeonEnginePipeLine/NEPipeLine.hpp"
#include "NeonEngineDevice/NEDevice.hpp"

namespace NeonEngine
{

    class FirstApp
    {
    public:
        static constexpr int WIDTH = 800;
        static constexpr int HEIGHT = 600;

        void run();

    private:
        NEWindow firstWindow{WIDTH, HEIGHT, "Vulkan Is Here!"};
        NEDevice neDevice{firstWindow};

        // Consider using a unique identifier for the pipeline instead of hardcoded filenames
        NEPipeLine pipeline{neDevice,
                            "../bin/shaders/SampleShader.vert.spv",
                            "../bin/shaders/SampleShader.frag.spv",
                            NEPipeLine::defaultPipeLineConfigInfo(WIDTH, HEIGHT)};

        void printWorkingDirectory()
        {
            std::cout << "Current working directory: "
                      << std::filesystem::current_path().string() << std::endl;
        }
    };

} // namespace NeonEngine
