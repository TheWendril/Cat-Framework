#include "../core/module.hpp"
#include "../mapek/meumapek.mapek.hpp"

class MeuModulo : public CAT::Module {

    void createModule() override {
        std::cout << "Criando Módulo MeuModulo" << std::endl;
        this->add(meumapek());
    }
};