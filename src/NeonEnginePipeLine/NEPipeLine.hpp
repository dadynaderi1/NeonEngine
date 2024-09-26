<<<<<<< HEAD
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
=======
// NEPipeline.hpp

#pragma once

#include "NeonEngineDevice/NEDevice.hpp"

// std
#include <string>
#include <vector>

namespace NeonEngine
{

    /// @brief Configuration information for a pipeline.
    ///
    /// This structure holds configuration options that can be used to customize the pipeline creation process.
    struct PipeLineConfigInfo
    {
        // Add specific fields here based on your pipeline requirements
        // Example:
        // uint32_t width;
        // uint32_t height;
        // VkRenderPass renderPass;
        // VkViewport viewport;
        // VkRect2D scissor;
    };

    /// @brief Represents a Vulkan pipeline.
    ///
    /// This class encapsulates the creation and management of a Vulkan graphics pipeline.
    class NEPipeLine
    {
    public:
        /// @brief Constructor.
        ///
        /// Creates a new `NEPipeLine` object.
        ///
        /// @param device Reference to the `NEDevice` object associated with this pipeline.
        /// @param vertexFilePath Path to the vertex shader file.
        /// @param fragmentFilePath Path to the fragment shader file.
        /// @param configInfo Configuration information for the pipeline.
        NEPipeLine(NEDevice &device, const std::string &vertexFilePath, const std::string &fragmentFilePath, const PipeLineConfigInfo &configInfo);

        /// @brief Destructor.
        ///
        /// Cleans up resources associated with the pipeline.
        ~NEPipeLine();

        // Not copyable or movable
        NEPipeLine(const NEPipeLine &) = delete;
        void operator=(const NEPipeLine &) = delete;
        NEPipeLine(NEPipeLine &&) = delete;
        NEPipeLine &operator=(NEPipeLine &&) = delete;

        /// @brief Gets the graphics pipeline handle.
        ///
        /// @return The graphics pipeline handle.
        VkPipeline getGraphicsPipeline() { return graphicsPipeline; }

        /// @brief Creates a default pipeline configuration info object.
        ///
        /// @param width The width of the viewport.
        /// @param height The height of the viewport.
        /// @return The default pipeline configuration info.
        static PipeLineConfigInfo defaultPipeLineConfigInfo(uint32_t width, uint32_t height);

    private:
        /// @brief Reads the contents of a file into a vector of characters.
        ///
        /// @param filePath Path to the file to read.
        /// @return A vector containing the file contents.
        static std::vector<char> readFile(const std::string &filePath);

        /// @brief Creates the graphics pipeline.
        ///
        /// This function sets up the pipeline layout, vertex input state, rasterizer state, and other pipeline stages.
        ///
        /// @param vertexFilePath Path to the vertex shader file.
        /// @param fragmentFilePath Path to the fragment shader file.
        /// @param configInfo Configuration information for the pipeline.
        void createGraphicsPipeLine(const std::string &vertexFilePath, const std::string &fragmentFilePath, const PipeLineConfigInfo &configInfo);

        /// @brief Creates a shader module from the given shader code.
        ///
        /// @param code The shader code.
        /// @param shaderModule Pointer to the shader module handle.
        void createShaderModule(const std::vector<char> &code, VkShaderModule *shaderModule);

        // interactions with vulkan

        NEDevice &neDevice;

        VkPipeline graphicsPipeline;

        VkShaderModule vertexShaderModule;

        VkShaderModule fragmentShaderModule;
    };

} // namespace NeonEngine
>>>>>>> Dev
