#!/bin/bash

set -e  # Exit immediately if a command exits with a non-zero status
set -u  # Treat unset variables as an error when substituting
set -o pipefail  # Consider failures in pipes

# Function to check and install dependencies
check_and_install() {
    for package in "$@"; do
        if ! command -v "$package" &> /dev/null; then
            echo "🔍 $package is not installed. Installing..."
            if sudo apt-get install -y "$package"; then
                echo "✅ $package installed successfully."
            else
                echo "❌ Failed to install $package. Please check your package manager."
                exit 1
            fi
        else
            echo "✅ $package is already installed."
        fi
    done
}

# Check for required dependencies
DEPENDENCIES=(glslc cmake ninja-build vulkan-tools libglfw3-dev libglm-dev)
check_and_install "${DEPENDENCIES[@]}"

# Ensure compile.sh is executable
if [ ! -x compile.sh ]; then
    chmod +x compile.sh
fi

# Run the shader compilation script
echo "🛠️ Starting shader compilation..."
if ./compile.sh; then
    echo "✅ Shader compilation completed successfully! Time to build the project!"
else
    echo "❌ Shader compilation failed. Please check the errors above."
    exit 1
fi

# Clean previous build if it exists
if [ -d "build" ]; then
    echo "🧹 Cleaning previous build..."
    rm -rf build
fi

# Create a new build directory and build
mkdir -p build
cd build

echo "🔧 Configuring the project with CMake..."
cmake -G Ninja ..

echo "🚀 Building the project with Ninja..."
ninja

# Optionally run the executable if the build was successful
if [ -f "./NeonEngine" ]; then
    echo "🚀 Running the NeonEngine executable..."
    ./NeonEngine
else
    echo "❌ NeonEngine executable not found. Build may have failed."
    exit 1
fi

echo "🎉 Done! Your project is all set up!"
