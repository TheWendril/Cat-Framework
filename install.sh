#!/bin/bash

[ "$EUID" -ne 0 ] && exec sudo "$0" "$@"

PROJECT_NAME="cat"
LIB_NAME="lib${PROJECT_NAME}.a"
BUILD_DIR="build"

INSTALL_LIB_DIR="/usr/local/lib"
INSTALL_INCLUDE_DIR="/usr/local/include/Cat"
INSTALL_BIN_DIR="/usr/bin"
CLI_NAME="catcli"
TEMPLATE_SOURCE_DIR="template"
TEMPLATE_INSTALL_DIR="/usr/share/catframework/template"

rm -rf "$BUILD_DIR"
mkdir -p "$BUILD_DIR"

echo "Compiling static library..."
find ./core -name '*.cpp' | while read file; do
  obj_file="$BUILD_DIR/$(basename "${file%.cpp}.o")"
  g++ -c "$file" -o "$obj_file" -std=c++17 -O2
done

echo "Generating Static Library $LIB_NAME..."
ar rcs "$BUILD_DIR/$LIB_NAME" $BUILD_DIR/*.o

echo "Installing Library in $INSTALL_LIB_DIR..."
sudo cp "$BUILD_DIR/$LIB_NAME" "$INSTALL_LIB_DIR"

echo "Installing Headers in $INSTALL_INCLUDE_DIR..."
sudo mkdir -p "$INSTALL_INCLUDE_DIR"
sudo cp -r core/* "$INSTALL_INCLUDE_DIR"

echo "Building CLI binary..."
g++ cli/catcli.cpp -o "$BUILD_DIR/$CLI_NAME" -std=c++17 -O2 -Icore -L"$BUILD_DIR" -lcat

echo "Installing template files in $TEMPLATE_INSTALL_DIR..."
rm -rf "$TEMPLATE_INSTALL_DIR"
mkdir -p "$TEMPLATE_INSTALL_DIR"
cp -r "$TEMPLATE_SOURCE_DIR"/* "$TEMPLATE_INSTALL_DIR"

echo "Installing CLI binary in $INSTALL_BIN_DIR..."
sudo cp "$BUILD_DIR/$CLI_NAME" "$INSTALL_BIN_DIR"
rm -r "$BUILD_DIR"

echo "Finished. You can now run: $CLI_NAME help"
echo "You can include with: #include <Cat/app.hpp>"
