# Create a library for the NeonEngineWindow component
add_library(NeonEngineWindowLib NEWindow.cpp)

# Specify include directories for header files in the NeonEngineWindow folder
target_include_directories(NeonEngineWindowLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
