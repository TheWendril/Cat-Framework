#!/bin/bash

if [ "$EUID" -eq 0 ]; then
  echo "❌ Não execute este script como root diretamente."
  echo "Use: ./install-esp.sh (sem sudo)"
  exit 1
fi

. "$HOME/esp/esp-idf/export.sh"
export PATH="$(dirname "$(which xtensa-esp32-elf-g++)"):$PATH"

PROJECT_NAME="cat"
LIB_NAME="lib${PROJECT_NAME}.a"
BUILD_DIR="build_xtensa"
BUILD_DIR_CLI="build_cli"

INSTALL_LIB_DIR="/usr/local/lib"
INSTALL_INCLUDE_DIR="/usr/local/include/Cat"
INSTALL_BIN_DIR="/usr/bin"
CLI_NAME="catcli"
TEMPLATE_SOURCE_DIR="template"
TEMPLATE_INSTALL_DIR="/usr/share/catframework/template"

XTENSA_PREFIX="xtensa-esp32-elf-"
CXXFLAGS_XTENSA="-std=c++17 -O2 -mlongcalls -Wno-frame-address -nostartfiles"

rm -rf "$BUILD_DIR" "$BUILD_DIR_CLI"
mkdir -p "$BUILD_DIR" "$BUILD_DIR_CLI"

echo "Compiling static library for Xtensa (ESP32)..."
find ./core -name '*.cpp' | while read -r file; do
  obj_file="$BUILD_DIR/$(basename "${file%.cpp}.o")"
  ${XTENSA_PREFIX}g++ -c "$file" -o "$obj_file" $CXXFLAGS_XTENSA -Icore
done

echo "Generating Static Library $LIB_NAME (Xtensa)..."
${XTENSA_PREFIX}ar rcs "$BUILD_DIR/$LIB_NAME" $BUILD_DIR/*.o

echo "Installing Library in $INSTALL_LIB_DIR..."
sudo cp "$BUILD_DIR/$LIB_NAME" "$INSTALL_LIB_DIR"

echo "Installing Headers in $INSTALL_INCLUDE_DIR..."
sudo mkdir -p "$INSTALL_INCLUDE_DIR"
sudo cp -r core/* "$INSTALL_INCLUDE_DIR"

echo "Building CLI binary for desktop (host)..."
g++ cli/catcli.cpp -o "$BUILD_DIR_CLI/$CLI_NAME" -std=c++17 -O2 -Icore -L"$BUILD_DIR" 

echo "Installing template files in $TEMPLATE_INSTALL_DIR..."
sudo rm -rf "$TEMPLATE_INSTALL_DIR"
sudo mkdir -p "$TEMPLATE_INSTALL_DIR"
sudo cp -r "$TEMPLATE_SOURCE_DIR"/* "$TEMPLATE_INSTALL_DIR"

echo "Installing CLI binary in $INSTALL_BIN_DIR..."
sudo cp "$BUILD_DIR_CLI/$CLI_NAME" "$INSTALL_BIN_DIR"

rm -rf "$BUILD_DIR" "$BUILD_DIR_CLI"

echo "Finished. You can now run: $CLI_NAME help"
echo "You can include with: #include <Cat/app.hpp>"
