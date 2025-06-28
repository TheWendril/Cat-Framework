#include "../core/module.hpp"
#include "../mapek/meumapek.mapek.hpp"
#include <memory>

class DefaultModule : public CAT::Module {

public:
    std::shared_ptr<MMPK> mmpk = std::make_shared<MMPK>();

    void createModule() override {
        this->add(mmpk);
    }
};