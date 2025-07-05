#!/bin/bash

[ "$EUID" -ne 0 ] && exec sudo "$0" "$@"

PROJECT_NAME="cat"
LIB_NAME="lib${PROJECT_NAME}.a"
INSTALL_LIB_DIR="/usr/local/lib"
INSTALL_INCLUDE_DIR="/usr/local/include/Cat"
INSTALL_BIN_DIR="/usr/bin"
CLI_NAME="catcli"
TEMPLATE_INSTALL_DIR="/usr/share/catframework/template"
TEMPLATE_ROOT_DIR="/usr/share/catframework"

echo "🧹 Removing library..."
rm -f "$INSTALL_LIB_DIR/$LIB_NAME"

echo "🧹 Removing headers..."
rm -rf "$INSTALL_INCLUDE_DIR"

echo "🧹 Removing CLI..."
rm -f "$INSTALL_BIN_DIR/$CLI_NAME"

echo "🧹 Removing template..."
rm -rf "$TEMPLATE_INSTALL_DIR"

# Remove o diretório pai se estiver vazio
if [ -d "$TEMPLATE_ROOT_DIR" ] && [ ! "$(ls -A "$TEMPLATE_ROOT_DIR")" ]; then
  rmdir "$TEMPLATE_ROOT_DIR"
fi

echo "✅ Uninstall Finished. Please give me a feedback on my github and i hope to see you soon :3"
