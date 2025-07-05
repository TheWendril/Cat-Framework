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
    std::cout << "  help               Show this help message\n";
    std::cout << "  init <project>     Initialize a new project\n";
    std::cout << "  build              Build the project\n";
    std::cout << "  run                Build and run the project\n";
}

void handleBuild() {
    printLogo();
    std::cout << "🔨 Building project..." << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(3));
    
    std::system("rm -rf dist");
    std::system("mkdir dist");

    int result = std::system("g++ -g -std=c++17 main.cpp -o dist/app -Icore -Lbuild -lcat");
    if (result == 0) {
        std::cout << "😻 Success!" << std::endl;
        std::cout << "📂 Your binary file is in the dist folder" << std::endl;
    } else {
        std::cerr << "😿 Compilation ended with error..." << std::endl;
    }
}

void handleInit(const std::string& projectName) {
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

    std::this_thread::sleep_for(std::chrono::seconds(3));
    std::cout << "😸 Project \"" << projectName << "\" initialized with template!" << std::endl;
}

void handleRun() {
    
    printLogo();
    std::cout << "🔨 Building project..." << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(3));
    
    std::system("rm -rf dist");
    std::system("mkdir dist");

    int result = std::system("g++ -g -std=c++17 main.cpp -o dist/app -Icore -Lbuild -lcat");
    if (result == 0) {
        std::cout << "😻 Success!" << std::endl;
        std::cout << "📂 Your binary file is in the dist folder" << std::endl;
    } else {
        std::cerr << "😿 Compilation ended with error..." << std::endl;
        return;
    }

    std::cout << "🐈 Runnning your project..." << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(3));
    std::system("./dist/app");
}

int main(int argc, char* argv[]) {

    if (argc < 2) {
        std::cerr << "❌ No command provided. Use 'help' to see available commands." << std::endl;
        return 1;
    }

    std::string command = argv[1];

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
        handleInit(argv[2]);
    } else {
        std::cerr << "❌ Unknown command: " << command << "\nUse 'help' to see available commands." << std::endl;
        return 1;
    }

    return 0;
}
