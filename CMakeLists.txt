cmake_minimum_required(VERSION 3.10)
project(NeonEngine LANGUAGES CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Set output directories for different build types
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/lib/${CMAKE_BUILD_TYPE})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/lib/${CMAKE_BUILD_TYPE})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin/${CMAKE_BUILD_TYPE})

# Set the option to build shared libraries
set(BUILD_SHARED_LIBS ON)

# Find packages
find_package(Vulkan REQUIRED)
find_package(glfw3 REQUIRED CONFIG)
find_package(glm REQUIRED)

# Include directories for GLM (header-only)
include_directories(${GLM_INCLUDE_DIRS})

# Include directories for the project's source files
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

# Add executable
add_executable(NeonEngine ${SOURCE_FILES})

# Link libraries
target_link_libraries(NeonEngine PRIVATE glfw Vulkan::Vulkan)

# Shader files
set(SPIRV_FILES
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Shaders/SampleShader.frag.spv
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Shaders/SampleShader.vert.spv
)

# Ensure shaders directory exists
file(MAKE_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/shaders)

# Copy .spv files to the shaders directory next to the binary
foreach(SPIRV_FILE ${SPIRV_FILES})
    get_filename_component(SPIRV_NAME ${SPIRV_FILE} NAME)
    
    add_custom_command(
        TARGET NeonEngine POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy ${SPIRV_FILE} ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/shaders/${SPIRV_NAME}
        COMMENT "Copying shader ${SPIRV_NAME} to shaders directory"
    )
endforeach()

# Add a custom target for documentation generation
add_custom_target(doc
    COMMAND doxygen Doxyfile
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    COMMENT "Generating documentation with Doxygen"
)

# Optional: Set compiler options based on build type
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    target_compile_options(NeonEngine PRIVATE -DDEBUG)
endif()

# Create Visual Studio solution if on Windows
if(WIN32)
    set(CMAKE_GENERATOR "Visual Studio 16 2019")  # Specify the version you want to use
endif()
