#pragma once

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
        NEPipeLine NeonEnginePipeLine{neDevice, "src/Shaders/SampleShader.vert.spv", "src/Shaders/SampleShader.frag.spv", NEPipeLine::defaultPipeLineConfigInfo(WIDTH, HEIGHT)};
    };

} // namespace NeonEngine
