#include "../core/module.hpp"
#include "../mapek/meumapek.mapek.hpp"
#include <memory>

class MeuModulo : public CAT::Module {

public:
    std::shared_ptr<MMPK> mmpk;
    
    MeuModulo() : mmpk(std::make_shared<MMPK>()) {
        this->createModule();
    }

    void createModule() override {
        std::cout << "Criando Módulo MeuModulo" << std::endl;
        this->add(mmpk);
    }
};