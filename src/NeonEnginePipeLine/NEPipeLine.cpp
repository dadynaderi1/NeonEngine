<<<<<<< HEAD
#pragma once
#include "NEPipeLine.hpp"
// std
#include <fstream>
#include <stdexcept>
#include <iostream>
namespace NeonEngine
{
    NEPipeLine::NEPipeLine(const std::string &vertexFilePath, const std::string &fragmentFilePath)
    {
        createGraphicsPipeLine(vertexFilePath, fragmentFilePath);
    }
    std::vector<char> NEPipeLine::readFile(const std::string &filePath)
    {
        //, std::ios::ate | std::ios::binary
        std::fstream file(filePath, std::ios::in | std::ios::out | std::ios::ate | std::ios::binary);
        std::cout << "is file open:" << file.is_open() << std::endl;
        if (!file.is_open())
        {
            throw std::runtime_error("Failed to open file " + filePath);
        }
        else
        {
            std::cout << "file is open : " << filePath << std::endl;
        }
        size_t fileSize = static_cast<size_t>(file.tellg());
        std::vector<char> buffer(fileSize);

        file.seekg(0);
        file.read(buffer.data(), fileSize);

        file.close();
        return buffer;
    }
    void NEPipeLine::createGraphicsPipeLine(const std::string &vertexFilePath, const std::string &fragmentFilePath)
    {
        auto vertexCode = readFile(vertexFilePath);
        auto fragmentCode = readFile(fragmentFilePath);

        std::cout << "Vert Shader code size: " << vertexCode.size() << std::endl;
        std::cout << "frag Shader code size: " << fragmentCode.size() << std::endl;
    }

} // namespace NeonEngine
=======
// NEPipeline.cpp

#pragma once

#include "NEPipeLine.hpp"

// std

#include <fstream>

#include <stdexcept>

#include <iostream>

namespace NeonEngine

{

    NEPipeLine::NEPipeLine(NEDevice &device, const std::string &vertexFilePath, const std::string &fragmentFilePath, const PipeLineConfigInfo &configInfo) : neDevice{device}

    {

        createGraphicsPipeLine(vertexFilePath, fragmentFilePath, configInfo);
    }

    NEPipeLine::~NEPipeLine() {}

    std::vector<char> NEPipeLine::readFile(const std::string &filePath)

    {

        //, std::ios::ate | std::ios::binary

        std::fstream file(filePath, std::ios::in | std::ios::out | std::ios::ate | std::ios::binary);

        std::cout << "is file open:" << file.is_open() << std::endl;

        if (!file.is_open())

        {

            throw std::runtime_error("Failed to open file " + filePath);
        }

        else

        {

            std::cout << "file is open : " << filePath << std::endl;
        }

        size_t fileSize = static_cast<size_t>(file.tellg());

        std::vector<char> buffer(fileSize);

        file.seekg(0);

        file.read(buffer.data(), fileSize);

        file.close();

        return buffer;
    }

    void NEPipeLine::createGraphicsPipeLine(const std::string &vertexFilePath, const std::string &fragmentFilePath, const PipeLineConfigInfo &configInfo)

    {

        auto vertexCode = readFile(vertexFilePath);

        auto fragmentCode = readFile(fragmentFilePath);

        std::cout << "Vert Shader code size: " << vertexCode.size() << std::endl;

        std::cout << "frag Shader code size: " << fragmentCode.size() << std::endl;
    }

    void NEPipeLine::createShaderModule(const std::vector<char> &code, VkShaderModule *shaderModule)

    {

        VkShaderModuleCreateInfo createInfo{};

        createInfo.sType = VK_STRUCTURE_TYPE_SHADER_MODULE_CREATE_INFO;

        createInfo.codeSize = code.size();

        createInfo.pCode = reinterpret_cast<const uint32_t *>(code.data());

        if (vkCreateShaderModule(neDevice.device(), &createInfo, nullptr, shaderModule) == VK_FALSE)

        {

            throw std::runtime_error("Failed to create shader module...");
        }
    }

    PipeLineConfigInfo NEPipeLine::defaultPipeLineConfigInfo(uint32_t width, uint32_t height)

    {

        PipeLineConfigInfo configInfo{};

        return configInfo;
    }

} // namespace NeonEngine
>>>>>>> Dev
