#include <Cat/module.hpp>
#include "../mapek/default.mapek.hpp"
#include <memory>

class DefaultModule : public CAT::Module {

public:
    std::shared_ptr<MMPK> mmpk = std::make_shared<MMPK>();
    std::shared_ptr<MMPK> mmpk2 = std::make_shared<MMPK>();


    void createModule() override {
        this->add(mmpk);
        this->add(mmpk2);
    }
};