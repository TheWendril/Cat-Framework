// written by Wendril Avila

/*
    Main file for Cat CLI 
    "Simplify. Evaluate. Move forward."
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
 ( o.o )  "Simplify. Evaluate. Move forward."
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
        
        std::system(". ~/esp/esp-idf/export.sh");
        std::system("python -m pip install pyyaml");
        setenv("IDF_TARGET", platform.c_str(), 1);
        
        std::ostringstream cmd;
        cmd << "idf.py set-target " << platform;
        std::system(cmd.str().c_str());

        int result = std::system("idf.py -B dist build");
        if (result == 0) {
            std::cout << "😻 ESP32 build success! Check the build output in: ./dist" << std::endl;
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

    if (platform == "amd64") {
        fs::copy_file(templatePath / "main.cpp", projectPath / "main.cpp", fs::copy_options::overwrite_existing);
    } else if (platform.rfind("esp", 0) == 0) {
        fs::path mainDir = projectPath / "main";
        fs::create_directories(mainDir);
        fs::copy_file(templatePath / "main.esp.cpp", mainDir / "main.cpp", fs::copy_options::overwrite_existing);
    }

    for (const auto& entry : fs::recursive_directory_iterator(templatePath)) {
        const fs::path& from = entry.path();
        fs::path relativePath = fs::relative(from, templatePath);
        fs::path to = projectPath / relativePath;

        if (relativePath == "main.cpp" || relativePath == "main.esp.cpp") continue;

        if (fs::is_directory(from)) {
            fs::create_directories(to);
        } else if (fs::is_regular_file(from)) {
            fs::copy_file(from, to, fs::copy_options::overwrite_existing);
        }
    }

    std::ofstream configFile(projectPath / "cat.config.txt");
    configFile << "project_name=" << projectName << std::endl;
    configFile << "platform=" << platform << std::endl;
    configFile << "debug=" << debug << std::endl;
    configFile.close();

    if (platform.rfind("esp", 0) == 0) {

        std::ofstream cmakeRoot(projectPath / "CMakeLists.txt");
        cmakeRoot << "cmake_minimum_required(VERSION 3.5)\n";
        cmakeRoot << "set(EXTRA_COMPONENT_DIRS main)\n";
        cmakeRoot << "set(CXX_FLAGS \"${CXX_FLAGS} -frtti -fexceptions\")\n";
        cmakeRoot << "include($ENV{IDF_PATH}/tools/cmake/project.cmake)\n";
        cmakeRoot << "project(" << projectName << ")\n";
        cmakeRoot.close();

        fs::path mainDir = projectPath / "main";
        fs::create_directories(mainDir);
        std::ofstream cmakeMain(mainDir / "CMakeLists.txt");
        cmakeMain << "idf_component_register(SRCS \"main.cpp\" \"/opt/catframework/esp32/include/Cat/loopComponent.cpp\" INCLUDE_DIRS \".\")\n";
        cmakeMain << "include_directories(/opt/catframework/esp32/include)\n";
        cmakeMain << "target_link_libraries(${COMPONENT_LIB} INTERFACE /opt/catframework/esp32/lib/libcat.a)\n";
        cmakeMain << "target_compile_definitions(${COMPONENT_LIB} PRIVATE ESP_PLATFORM)\n";
        cmakeMain.close();

        std::ofstream sdkconfig(projectPath / "sdkconfig.defaults");
        sdkconfig << "CONFIG_ESP_CONSOLE_USB_CDC=y\n";
        sdkconfig << "CONFIG_USB_CDC_ENABLED=y\n";
        sdkconfig << "CONFIG_ESP_CONSOLE_STDOUT_USB_CDC=y\n";
        sdkconfig.close();
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

        std::string debug = "false";
        std::ifstream configFile("cat.config.txt");
        std::string line;
        while (std::getline(configFile, line)) {
            if (line.rfind("debug=", 0) == 0) {
                debug = line.substr(6);
                break;
            }
        }
        std::string port;
        FILE* pipe = popen("ls /dev/ttyUSB* /dev/ttyACM* 2>/dev/null | head -n 1", "r");
        if (pipe) {
            char buffer[256];
            if (fgets(buffer, sizeof(buffer), pipe)) {
                port = std::string(buffer);
                size_t pos = port.find('\n');
                if (pos != std::string::npos) port.erase(pos);
            }
            pclose(pipe);
        }
        if (port.empty()) {
            std::cerr << "❌ No ESP32 board detected (no /dev/ttyUSB* or /dev/ttyACM* found). Connect your board and try again." << std::endl;
            return;
        }
        std::cout << "🔌 Flashing your ESP32 on port: " << port << std::endl;
        std::ostringstream cmd;
        cmd << "idf.py -p " << port << " --build-dir=dist flash";
        int flashResult = std::system(cmd.str().c_str());
        if (flashResult == 0 && debug == "true") {
            std::this_thread::sleep_for(std::chrono::seconds(3));
            std::cout << "🪲 Debug enabled. Opening monitor..." << std::endl;
            std::ostringstream monitorCmd;
            monitorCmd << "idf.py -p " << port << " monitor";
            std::system(monitorCmd.str().c_str());
        } else if (flashResult == 0) {
            std::cout << "✅ Flash complete! (monitor not started, debug=false)" << std::endl;
        } else {
            std::cerr << "😿 Flash failed..." << std::endl;
        }
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
