cmake_minimum_required(VERSION 3.10)

# Project name
project(NeonEngine LANGUAGES CXX)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Use the Ninja generator if available
if(NOT CMAKE_GENERATOR MATCHES "Ninja")
    message(WARNING "Consider using the Ninja generator for faster builds.")
endif()

# Include directories
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src/TestApps)

# Source files
set(SOURCE_FILES
    src/main.cpp
    src/NeonEngineDevice/NEDevice.cpp
    src/NeonEnginePipeLine/NEPipeLine.cpp
    src/NeonEngineWindow/NEWindow.cpp
    src/TestApps/FirstApp.cpp
)

# Header files (for IDEs)
set(HEADER_FILES
    src/NeonEngineDevice/NEDevice.hpp
    src/NeonEnginePipeLine/NEPipeLine.hpp
    src/NeonEngineWindow/NEWindow.hpp
    src/TestApps/FirstApp.hpp
)

# Add executable
add_executable(NeonEngine ${SOURCE_FILES} ${HEADER_FILES})

# Find Vulkan package
find_package(Vulkan REQUIRED)

# Link libraries
target_link_libraries(NeonEngine
    glfw
    Vulkan::Vulkan  # Link against Vulkan
    dl
    pthread
    X11
    Xxf86vm
    Xrandr
    Xi
)

# Shader files
set(SPIRV_FILES
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Shaders/SampleShader.frag.spv
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Shaders/SampleShader.vert.spv
)

# Copy .spv files to the executable directory
foreach(SPIRV_FILE ${SPIRV_FILES})
    get_filename_component(SPIRV_NAME ${SPIRV_FILE} NAME)
    
    add_custom_command(
        TARGET NeonEngine POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy ${SPIRV_FILE} $<TARGET_FILE_DIR:NeonEngine>/${SPIRV_NAME}
        COMMENT "Copying shader ${SPIRV_NAME} to executable directory"
    )
endforeach()

# Installation (optional)
install(TARGETS NeonEngine DESTINATION bin)

# Add a custom target for documentation generation
add_custom_target(doc
    COMMAND doxygen Doxyfile
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    COMMENT "Generating documentation with Doxygen"
)
