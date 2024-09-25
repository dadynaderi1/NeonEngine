# Create a library for the FirstApp component
add_library(srcLib FirstApp.cpp)

# Specify include directories for header files in the src folder
target_include_directories(srcLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})