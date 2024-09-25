#pragma once
#include <string>
#include <vector>
namespace NeonEngine
{
    class NEPipeLine
    {
    public:
        NEPipeLine(const std::string &vertexFilePath, const std::string &fragmentFilePath);

    private:
        static std::vector<char> readFile(const std::string &filePath);
        void createGraphicsPipeLine(const std::string &vertexFilePath, const std::string &fragmentFilePath);
    };
} // namespace NeonEngine
