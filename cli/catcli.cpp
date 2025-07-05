// written by Wendril Avila

/*
    Main file for Cat CLI 
    "Always make the simple as possible, evaluate, forward"
*/

#include <iostream>
#include <string>
#include <filesystem>
#include <fstream>
#include <vector>
#include <thread>
#include <chrono>
#include <sstream>


namespace fs = std::filesystem;

void printLogo() {
    std::cout << R"(
  /\_/\   Cat Framework CLI
 ( o.o )  "Always make the simple as possible, evaluate, forward"
<  ^ ^ 
-------------------------------------------------------------
)" << std::endl;
}

void printHelp() {
    printLogo();
    std::cout << "Cat CLI - available commands:\n";
    std::cout << "  help                              Show this help message\n";
    std::cout << "  init <project> [--platform <amd64|esp32s2|esp32s3|esp32>] [--debug <true|false>]\n";
    std::cout << "                                    Initialize a new project (default: amd64, debug: false)\n";
    std::cout << "  build                             Build the project for the current platform in cat.config.txt\n";
    std::cout << "  run                               Build and run the project for the current platform in cat.config.txt\n";
}

std::string getProjectNameFromConfig() {
    std::ifstream configFile("cat.config.txt");
    std::string line;
    while (std::getline(configFile, line)) {
        if (line.rfind("project_name=", 0) == 0) {
            return line.substr(13);
        }
    }
    return "app";
}

std::string getPlatformFromConfig() {
    std::ifstream configFile("cat.config.txt");
    std::string line;
    while (std::getline(configFile, line)) {
        if (line.rfind("platform=", 0) == 0) {
            return line.substr(9);
        }
    }
    return "amd64";
}

void handleBuild() {
    printLogo();
    std::string platform = getPlatformFromConfig();
    std::string projectName = getProjectNameFromConfig();
    std::cout << "🔨 Building project for platform: " << platform << "..." << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(1));

    std::system("rm -rf dist");
    std::system("mkdir dist");

    if (platform == "amd64") {
        std::ostringstream cmd;
        cmd << "g++ -g -std=c++17 main.cpp -o dist/" << projectName << " -Icore -Lbuild -lcat";
        int result = std::system(cmd.str().c_str());
        if (result == 0) {
            std::cout << "😻 Success!" << std::endl;
            std::cout << "📂 Your binary file is in the dist folder: dist/" << projectName << std::endl;
        } else {
            std::cerr << "😿 Compilation ended with error..." << std::endl;
        }
    } else if (platform.rfind("esp", 0) == 0) {
        int result = std::system("idf.py build");
        if (result == 0) {
            std::cout << "😻 ESP32 build success! Check the build output in: ./build" << std::endl;
        } else {
            std::cerr << "😿 ESP32 build failed..." << std::endl;
        }
    } else {
        std::cerr << "❌ Unknown platform: " << platform << std::endl;
    }
}

void handleInit(const std::string& projectName, const std::string& platform, const std::string& debug) {
    printLogo();
    std::cout << "📦 Initializing project: " << projectName << std::endl;

    const fs::path templatePath = "/usr/share/catframework/template";
    const fs::path projectPath = projectName;

    if (!fs::exists(templatePath)) {
        std::cerr << "❌ Err: Template not found in " << templatePath << std::endl;
        return;
    }

    if (fs::exists(projectPath)) {
        std::cerr << "❌ Err: Directory \"" << projectName << "\" already exists." << std::endl;
        return;
    }

    fs::create_directories(projectPath);

    for (const auto& entry : fs::recursive_directory_iterator(templatePath)) {
        const fs::path& from = entry.path();
        fs::path relativePath = fs::relative(from, templatePath);
        fs::path to = projectPath / relativePath;

        if (fs::is_directory(from)) {
            fs::create_directories(to);
        } else if (fs::is_regular_file(from)) {
            fs::copy_file(from, to, fs::copy_options::overwrite_existing);
        }
    }

    // Gera o arquivo de configuração
    std::ofstream configFile(projectPath / "cat.config.txt");
    configFile << "project_name=" << projectName << std::endl;
    configFile << "platform=" << platform << std::endl;
    configFile << "debug=" << debug << std::endl;
    configFile.close();

    // Se for plataforma ESP, gera CMakeLists.txt raiz e main/
    if (platform.rfind("esp", 0) == 0) {
        // CMakeLists.txt na raiz
        std::ofstream cmakeRoot(projectPath / "CMakeLists.txt");
        cmakeRoot << "cmake_minimum_required(VERSION 3.5)\n";
        cmakeRoot << "include($ENV{IDF_PATH}/tools/cmake/project.cmake)\n";
        cmakeRoot << "project(" << projectName << ")\n";
        cmakeRoot.close();
    }

    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << "😸 Project \"" << projectName << "\" initialized with template!" << std::endl;
    std::cout << "📝 Config file generated at: " << (projectPath / "cat.config.txt") << std::endl;
}

void handleRun() {
    std::string platform = getPlatformFromConfig();
    std::string projectName = getProjectNameFromConfig();
    handleBuild();
    if (platform == "amd64") {
        std::cout << "🐈 Running your project..." << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::string runCmd = "./dist/" + projectName;
        std::system(runCmd.c_str());
    } else if (platform.rfind("esp", 0) == 0) {
        std::cout << "🔌 To flash and monitor your ESP32, run:\n";
        std::cout << "    idf.py -p <PORT> flash monitor\n";
    } else {
        std::cerr << "❌ Unknown platform: " << platform << std::endl;
    }
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "❌ No command provided. Use 'help' to see available commands." << std::endl;
        return 1;
    }

    std::string command = argv[1];
    std::string platform = "amd64";
    std::string debug = "false";

    // Parse flags for init only
    for (int i = 2; i < argc; ++i) {
        std::string arg = argv[i];
        if (arg == "--platform" && i + 1 < argc) {
            platform = argv[++i];
        } else if (arg == "--debug" && i + 1 < argc) {
            debug = argv[++i];
        }
    }

    if (command == "help") {
        printHelp();
    } else if (command == "build") {
        handleBuild();
    } else if (command == "run") {
        handleRun();
    } else if (command == "init") {
        if (argc < 3) {
            std::cerr << "❌ Please provide a project name: cat init <project_name>" << std::endl;
            return 1;
        }
        handleInit(argv[2], platform, debug);
    } else {
        std::cerr << "❌ Unknown command: " << command << "\nUse 'help' to see available commands." << std::endl;
        return 1;
    }

    return 0;
}
