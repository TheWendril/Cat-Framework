#include "../core/model/strategySet.hpp"
#include "action.hpp"

class MSS : public CAT::StrategySet {

public:


    MSS(){
        this->create();
    }


    void create() override {
        std::shared_ptr<CAT::Action> acao = std::make_shared<MinhaAcao>();
        this->addAction(acao);
    }

};