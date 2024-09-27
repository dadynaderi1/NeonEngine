@echo off
setlocal

:: Check for required tools
set TOOLS=cmake ninja
for %%T in (%TOOLS%) do (
    where %%T >nul 2>nul
    if errorlevel 1 (
        echo %%T is not installed. Please install it from their respective websites.
        exit /b 1
    )
)

:: Clean previous builds
if "%1"=="clean" (
    echo Cleaning previous builds...
    rmdir /s /q build
    rmdir /s /q bin
    rmdir /s /q lib
    echo Cleaned build, bin, and lib directories.
    exit /b 0
)

:: Inform the user to install the Vulkan SDK
echo Please install the LunarG Vulkan SDK from https://vulkan.lunarg.com/ before proceeding.
echo After installation, make sure to set the necessary environment variables.

:: Create and navigate to build directory
if exist build (
    echo Cleaning previous build...
    rmdir /s /q build
)
mkdir build
cd build

:: Configure the project
echo Configuring the project with CMake...
cmake -G Ninja ..

:: Build the project
echo Building the project with Ninja...
ninja

:: Run the executable if it exists
if exist ..\bin\NeonEngine (
    echo Running the NeonEngine executable...
    ..\bin\NeonEngine
) else (
    echo NeonEngine executable not found. Build may have failed.
    exit /b 1
)

echo Done! Your project is all set up!

endlocal
