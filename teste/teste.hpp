#include "../core/model/strategySet.hpp"
#include "action.hpp"

class Teste : public CAT::StrategySet {

public:

    Teste(){
        MinhaAcao * minhaacao;
        this->addAction(minhaacao);
        std::cout << "criando função" << std::endl;
    }
      
};