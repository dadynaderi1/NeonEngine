#pragma once

#include "NeonEngineWindow/NEWindow.hpp"
#include "NeonEnginePipeLine/NEPipeLine.hpp"
<<<<<<< HEAD
=======
#include "NeonEngineDevice/NEDevice.hpp"
>>>>>>> Dev

namespace NeonEngine
{

    class FirstApp
    {
    public:
        static constexpr int WIDTH = 800;
        static constexpr int HEIGHT = 600;

        void run();

    private:
<<<<<<< HEAD
        NeWindow firstWindow{WIDTH, HEIGHT, "Vulkan Is Here!"};
        NEPipeLine NeonEnginePipeLine{"src/Shaders/SampleShader.vert.spv", "src/Shaders/SampleShader.frag.spv"};
=======
        NEWindow firstWindow{WIDTH, HEIGHT, "Vulkan Is Here!"};
        NEDevice neDevice{firstWindow};

        // Consider using a unique identifier for the pipeline instead of hardcoded filenames
        NEPipeLine pipeline{neDevice,
                            "SampleShader.vert.spv",
                            "SampleShader.frag.spv",
                            NEPipeLine::defaultPipeLineConfigInfo(WIDTH, HEIGHT)};
>>>>>>> Dev
    };

} // namespace NeonEngine
