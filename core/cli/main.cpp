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

    int result = std::system("g++ -o ./dist/main main.cpp");
    if (result == 0) {
        std::cout << "😻 Success!" << std::endl;
    } else {
        std::cerr << "😿 Compilation ended with error..." << std::endl;
    }
}

void handleInit(const std::string& projectName) {
    printLogo();
    std::cout << "📦 Initializing project: " << projectName << std::endl;

    // Cria o diretório raiz
    fs::create_directory(projectName);

    // Subpastas
    std::vector<std::string> subfolders = {
        "behavior", "constraint", "mapek", "models", "modules", "strategy", "core", "core/enum", "core/model", "core/cli", "core/utils", "teste"
    };

    for (const auto& folder : subfolders) {
        fs::create_directories(projectName + "/" + folder);
    }

    // Arquivos de exemplo na raiz
    std::ofstream mainFile(projectName + "/main.cpp");
    mainFile << R"(#include <iostream>
#include "modules/default.module.hpp"
#include "core/app.hpp"

int main() {
    DefaultModule defaultModule;
    defaultModule.createModule();
    CAT::App app(defaultModule);
    app.start();
    return 0;
}
)";
    mainFile.close();

    std::ofstream readmeFile(projectName + "/README.md");
    readmeFile << "# Projeto Cat Framework\n\nEstrutura inicial gerada pelo Cat CLI.";
    readmeFile.close();

    std::ofstream installFile(projectName + "/install.sh");
    installFile << "#!/bin/bash\necho 'Instalando dependências...'\n";
    installFile.close();

    std::ofstream motorFile(projectName + "/motor.txt");
    motorFile << "0\n";
    motorFile.close();
    std::ofstream sensorFile(projectName + "/sensor.txt");
    sensorFile << "0\n";
    sensorFile.close();

    // Exemplos em subpastas
    std::ofstream monitorActionFile(projectName + "/behavior/monitorAction.hpp");
    monitorActionFile << R"(#include "../core/model/action.hpp"
#include <fstream>
#include "../models/ventilador.model.hpp"

class MonitorAction : public CAT::Action {
public:
    void act(CAT::Element * element) override {
        std::fstream sensor("sensor.txt");
        std::fstream motor("motor.txt");
        std::string sensorRead;
        std::getline(sensor, sensorRead);
        std::string motorRead;
        std::getline(motor, motorRead);
        auto a = std::make_shared<Ventilador>();
        a->power = std::stoi(motorRead);
        a->temperature = std::stoi(sensorRead);
        element->getLocalKnowledge()->setCurrentState(a);
        std::cout << "Monitorando" << std::endl;
    }
};
)";
    monitorActionFile.close();

    std::ofstream plannerActionFile(projectName + "/behavior/plannerAction.hpp");
    plannerActionFile << R"(#include "../core/model/action.hpp"
#include <iostream>

class PlannerAction : public CAT::Action {
public:
    void act(CAT::Element* element) override {
        std::cout << "Planejando..." << std::endl;
    }
};
)";
    plannerActionFile.close();

    std::ofstream constraintFile(projectName + "/constraint/default.constraint.hpp");
    constraintFile << R"(#include "../core/constraintModel.hpp"
#include "../models/ventilador.model.hpp"
#include <iostream>

class AConstraint : public CAT::ConstraintModel {
public:
    bool check(CAT::Knowledge* knowledge) override {
        auto* ventilador = dynamic_cast<Ventilador*>(knowledge->getCurrentState());
        std::cout << "Analisando: Analise 1" << std::endl;
        return ventilador && ventilador->temperature < 40;
    }
};
)";
    constraintFile.close();

    std::ofstream ventiladorFile(projectName + "/models/ventilador.model.hpp");
    ventiladorFile << R"(#pragma once
#include "../core/model/model.hpp"

class Ventilador : public CAT::Model {
public:
    int power = 0;
    int temperature = 0;
};
)";
    ventiladorFile.close();

    std::ofstream defaultModuleFile(projectName + "/modules/default.module.hpp");
    defaultModuleFile << R"(#pragma once
#include "../core/module.hpp"
#include "../mapek/default.mapek.hpp"
#include <memory>

class DefaultModule : public CAT::Module {
    std::shared_ptr<MMPK> mmpk;
public:
    DefaultModule() : mmpk(std::make_shared<MMPK>()) {}
    void createModule() override {
        std::cout << "Criando Módulo DefaultModule" << std::endl;
        this->add(mmpk);
    }
};
)";
    defaultModuleFile.close();

    std::ofstream defaultStrategySetFile(projectName + "/strategy/default.strategy.hpp");
    defaultStrategySetFile << R"(#pragma once
#include "../core/model/strategy.hpp"

class DefaultStrategySet : public CAT::Strategy {
public:
    void create() override {
        // Adicione ações à estratégia aqui
    }
};
)";
    defaultStrategySetFile.close();

    std::ofstream defaultMAPEKFile(projectName + "/mapek/default.mapek.hpp");
    defaultMAPEKFile << R"(#pragma once
#include "../core/mapek.hpp"
#include "../behavior/monitorAction.hpp"
#include "../behavior/plannerAction.hpp"
#include "../constraint/default.constraint.hpp"
#include <memory>

class MMPK : public CAT::MAPEK {
public:
    MMPK() { this->configure(); }
    void configure() override {
        auto monitorAction = std::make_shared<MonitorAction>();
        auto aConstraint = std::make_shared<AConstraint>();
        auto plannerAction = std::make_shared<PlannerAction>();
        this->addMonitorAction(monitorAction);
        this->addConstraint(aConstraint);
        this->addPlannerAction(plannerAction);
    }
};
)";
    defaultMAPEKFile.close();

    std::this_thread::sleep_for(std::chrono::seconds(3));
    std::cout << "😸 Project initialized!" << std::endl;

}

void handleRun() {}

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
