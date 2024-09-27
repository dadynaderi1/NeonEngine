#!/bin/bash

set -e  # Exit immediately if a command exits with a non-zero status
set -u  # Treat unset variables as an error when substituting
set -o pipefail  # Consider failures in pipes

# Function to check and install dependencies for apt-based distros
install_apt_dependencies() {
    local dependencies=("$@")
    for package in "${dependencies[@]}"; do
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

# Function to check and install dependencies for macOS
install_brew_dependencies() {
    local dependencies=("$@")
    for package in "${dependencies[@]}"; do
        if ! command -v "$package" &> /dev/null; then
            echo "🔍 $package is not installed. Installing..."
            if brew install "$package"; then
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

# Clean build option
if [[ "${1:-}" == "clean" ]]; then
    echo "🧹 Cleaning previous builds..."
    rm -rf build
    rm -rf bin
    rm -rf lib
    echo "✅ Cleaned build, bin, and lib directories."
    exit 0
fi

# Clone Git submodules if not already cloned
echo "🔄 Checking out submodules..."
if [ ! -d "external/glfw" ] || [ ! -d "external/glm" ]; then
    git submodule update --init --recursive
    echo "✅ Submodules checked out successfully."
else
    echo "✅ Submodules already cloned."
fi

# Determine OS and install dependencies
if [[ "$OSTYPE" == "linux-gnu"* ]]; then
    DEPENDENCIES=(glslc cmake ninja-build vulkan-tools libglfw3-dev libglm-dev)
    install_apt_dependencies "${DEPENDENCIES[@]}"
elif [[ "$OSTYPE" == "darwin"* ]]; then
    if ! command -v brew &> /dev/null; then
        echo "❌ Homebrew is not installed. Please install Homebrew first: https://brew.sh"
        exit 1
    fi
    DEPENDENCIES=(glslang-tools cmake ninja vulkan-tools glfw glm)
    install_brew_dependencies "${DEPENDENCIES[@]}"
else
    echo "❌ Unsupported OS: $OSTYPE"
    exit 1
fi

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
if [ -f "../bin/NeonEngine" ]; then
    echo "🚀 Running the NeonEngine executable..."
    ../bin/NeonEngine
else
    echo "❌ NeonEngine executable not found. Build may have failed."
    exit 1
fi

echo "🎉 Done! Your project is all set up!"
