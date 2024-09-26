#!/bin/bash

echo "🚀 Starting the shader compilation process! Get ready to rock! 🎸"

# Compile all .vert files
for shader in src/Shaders/*.vert; do
    if [[ -f $shader ]]; then
        output="${shader}.spv"  # Ensure the output file name has the correct extension
        echo "🎨 Compiling $shader to $output... Let's make some magic happen! ✨"
        /usr/bin/glslc "$shader" -o "$output"
        echo "✅ Successfully created $output! You're a shader wizard! 🧙‍♂️"
    else
        echo "🔍 No .vert files found. Keep looking for the hidden gems! 💎"
    fi
done

# Compile all .frag files
for shader in src/Shaders/*.frag; do
    if [[ -f $shader ]]; then
        output="${shader}.spv"  # Ensure the output file name has the correct extension
        echo "🎨 Compiling $shader to $output... Let's make some magic happen! ✨"
        /usr/bin/glslc "$shader" -o "$output"
        echo "✅ Successfully created $output! You're a shader wizard! 🧙‍♂️"
    else
        echo "🔍 No .frag files found. Keep looking for the hidden gems! 💎"
    fi
done

echo "🎉 All shaders compiled! Time to unleash your creativity! 🎆"
