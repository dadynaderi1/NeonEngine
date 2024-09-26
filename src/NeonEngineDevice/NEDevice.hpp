#pragma once

#include "NeonEngineWindow/NEWindow.hpp"

// std lib headers
#include <string>
#include <vector>
#include <optional> // For optional values

namespace NeonEngine
{

  /// @brief Details about the swap chain support for a physical device.
  struct SwapChainSupportDetails
  {
    VkSurfaceCapabilitiesKHR capabilities;
    std::vector<VkSurfaceFormatKHR> formats;
    std::vector<VkPresentModeKHR> presentModes;
  };

  /// @brief Indices of the graphics and present queue families.
  struct QueueFamilyIndices
  {
    uint32_t graphicsFamily;
    uint32_t presentFamily;

    /// @brief Checks if both graphics and present queue families are valid.
    ///
    /// @return True if both graphicsFamily and presentFamily are not `VK_QUEUE_FAMILY_IGNORED`, otherwise false.
    bool isComplete() const { return graphicsFamily != VK_QUEUE_FAMILY_IGNORED && presentFamily != VK_QUEUE_FAMILY_IGNORED; }
  };

  /// @class NEDevice
  ///
  /// Represents a Vulkan device object.
  ///
  /// This class provides methods for creating and managing a Vulkan device, including instance creation, device selection, queue family management, and resource allocation.
  class NEDevice
  {
  public:
#ifdef NDEBUG
    const bool enableValidationLayers = false;
#else
    const bool enableValidationLayers = true;
#endif

    /// @brief Constructor.
    ///
    /// Initializes a new `NEDevice` object.
    ///
    /// @param window Reference to a `NEWindow` object representing the window the application will render to.
    NEDevice(NEWindow &window);

    /// @brief Destructor.
    ///
    /// Cleans up resources associated with the device.
    ~NEDevice();

    // Not copyable or movable
    NEDevice(const NEDevice &) = delete;
    void operator=(const NEDevice &) = delete;
    NEDevice(NEDevice &&) = delete;
    NEDevice &operator=(NEDevice &&) = delete;

    /// @brief Gets the command pool associated with this device.
    ///
    /// @return The command pool.
    VkCommandPool getCommandPool() { return commandPool; }

    /// @brief Gets the Vulkan device handle.
    ///
    /// @return The Vulkan device handle.
    VkDevice device() { return device_; }

    /// @brief Gets the Vulkan surface associated with this device.
    ///
    /// @return The Vulkan surface handle.
    VkSurfaceKHR surface() { return surface_; }

    /// @brief Gets the graphics queue associated with this device.
    ///
    /// @return The graphics queue handle.
    VkQueue graphicsQueue() { return graphicsQueue_; }

    /// @brief Gets the present queue associated with this device.
    ///
    /// @return The present queue handle.
    VkQueue presentQueue() { return presentQueue_; }

    /// @brief Queries the swap chain support details for the physical device.
    ///
    /// @param physicalDevice The physical device to query.
    /// @return The swap chain support details.
    SwapChainSupportDetails getSwapChainSupport() { return querySwapChainSupport(physicalDevice); }

    /// @brief Finds a memory type that meets the specified requirements.
    ///
    /// @param typeFilter The memory type filter.
    /// @param properties The desired memory properties.
    /// @return The index of the memory type.
    uint32_t findMemoryType(uint32_t typeFilter, VkMemoryPropertyFlags properties);

    /// @brief Finds the queue families for the given physical device.
    ///
    /// @param physicalDevice The physical device to query.
    /// @return The queue family indices.
    QueueFamilyIndices findPhysicalQueueFamilies() { return findQueueFamilies(physicalDevice); }

    /// @brief Finds a supported format for an image.
    ///
    /// @param candidates The list of candidate formats.
    /// @param tiling The image tiling mode.
    /// @param features The required format features.
    /// @return The supported format.
    VkFormat findSupportedFormat(
        const std::vector<VkFormat> &candidates, VkImageTiling tiling, VkFormatFeatureFlags features);

    // Buffer Helper Functions
    void createBuffer(
        VkDeviceSize size,
        VkBufferUsageFlags usage,
        VkMemoryPropertyFlags properties,
        VkBuffer &buffer,
        VkDeviceMemory &bufferMemory);
    VkCommandBuffer beginSingleTimeCommands();
    void endSingleTimeCommands(VkCommandBuffer commandBuffer);
    void copyBuffer(VkBuffer srcBuffer, VkBuffer dstBuffer, VkDeviceSize size);
    void copyBufferToImage(
        VkBuffer buffer, VkImage image, uint32_t width, uint32_t height, uint32_t layerCount);

    void createImageWithInfo(
        const VkImageCreateInfo &imageInfo,
        VkMemoryPropertyFlags properties,
        VkImage &image,
        VkDeviceMemory &imageMemory);

    VkPhysicalDeviceProperties properties;

  private:
    void createInstance();
    void setupDebugMessenger();
    void createSurface();
    void pickPhysicalDevice();
    void createLogicalDevice();
    void createCommandPool();

    // helper functions
    bool isDeviceSuitable(VkPhysicalDevice device);
    std::vector<const char *> getRequiredExtensions();
    bool checkValidationLayerSupport();
    QueueFamilyIndices findQueueFamilies(VkPhysicalDevice device);
    void populateDebugMessengerCreateInfo(VkDebugUtilsMessengerCreateInfoEXT &createInfo);
    void hasGflwRequiredInstanceExtensions();
    bool checkDeviceExtensionSupport(VkPhysicalDevice device);
    SwapChainSupportDetails querySwapChainSupport(VkPhysicalDevice device);

    VkInstance instance;
    VkDebugUtilsMessengerEXT debugMessenger;
    VkPhysicalDevice physicalDevice = VK_NULL_HANDLE;
    NEWindow &window;
    VkCommandPool commandPool;

    VkDevice device_;
    VkSurfaceKHR surface_;
    VkQueue graphicsQueue_;
    VkQueue presentQueue_;

    const std::vector<const char *> validationLayers = {"VK_LAYER_KHRONOS_validation"};
    const std::vector<const char *> deviceExtensions = {VK_KHR_SWAPCHAIN_EXTENSION_NAME};
  };

} // namespace NeonEngine