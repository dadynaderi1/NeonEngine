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
