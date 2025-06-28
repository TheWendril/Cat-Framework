#!/bin/bash

PROJECT_NAME="cat"
LIB_NAME="lib${PROJECT_NAME}.a"
BUILD_DIR="build"

INSTALL_LIB_DIR="/usr/local/lib"
INSTALL_INCLUDE_DIR="/usr/local/include/Cat"

rm -rf "$BUILD_DIR"
mkdir -p "$BUILD_DIR"

echo "Compiling..."
find ./core -name '*.cpp' | while read file; do
  obj_file="$BUILD_DIR/$(basename "${file%.cpp}.o")"
  g++ -c "$file" -o "$obj_file" -std=c++17 -O2
done

echo "Generating Static Library $LIB_NAME..."
ar rcs "$BUILD_DIR/$LIB_NAME" $BUILD_DIR/*.o

echo "Installing Libraries in $INSTALL_LIB_DIR..."
sudo cp "$BUILD_DIR/$LIB_NAME" "$INSTALL_LIB_DIR"

echo "Installing Headers: $INSTALL_INCLUDE_DIR..."
sudo mkdir -p "$INSTALL_INCLUDE_DIR"
sudo cp -r core/* "$INSTALL_INCLUDE_DIR"

echo "Finished. You can include with: #include <Cat/app.hpp>"