#pragma once

#include "NeonEngineWindow/NEWindow.hpp"

namespace NeonEngine
{
    class FirstApp
    {
    public:
        static constexpr int WIDTH = 800;
        static constexpr int HEIGHT = 600;

        void run();

    private:
        NeWindow firstWindow{WIDTH, HEIGHT, "Vulkan Is Here!"};
    };

} // namespace NeonEngine