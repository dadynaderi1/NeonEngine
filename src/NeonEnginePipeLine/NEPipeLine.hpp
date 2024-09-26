#pragma once
#include "NeonEngineDevice/NEDevice.hpp"
// std
#include <string>
#include <vector>
namespace NeonEngine
{
    struct PipeLineConfigInfo
    {
    };

    class NEPipeLine
    {
    public:
        NEPipeLine(NEDevice &device, const std::string &vertexFilePath, const std::string &fragmentFilePath, const PipeLineConfigInfo &configInfo);
        ~NEPipeLine();
        NEPipeLine(const NEPipeLine &) = delete;
        void operator=(const NEPipeLine &) = delete;

        static PipeLineConfigInfo defaultPipeLineConfigInfo(uint32_t width, uint32_t height);

    private:
        static std::vector<char> readFile(const std::string &filePath);
        void createGraphicsPipeLine(const std::string &vertexFilePath, const std::string &fragmentFilePath, const PipeLineConfigInfo &configInfo);
        void createShaderModule(const std::vector<char> &code, VkShaderModule *shaderModule);

        // interactions with vulkan
        NEDevice &neDevice;
        VkPipeline graphicsPipeline;
        VkShaderModule vertexShaderModule;
        VkShaderModule fragmentShaderModule;
    };
} // namespace NeonEngine
