#include "../core/model/strategySet.hpp"

#include "../core/model/action.hpp"
#include <fstream>

class Action1 : public CAT::Action {

public:
    void act(CAT::Element * element) override {
        std::cout << "Ação 1" << std::endl;
    }
};

class Action2 : public CAT::Action {

public:
    void act(CAT::Element * element) override {
        

        auto* ventilador = dynamic_cast<Ventilador*>(element->getLocalKnowledge()->getCurrentState());

        int newPower = (static_cast<double>(ventilador->temperature) / 50.0 + 1.0) * ventilador->power;
        
        std::fstream motor("motor.txt");
        motor.clear();
        motor << newPower << std::endl;
        std::cout << newPower << std::endl;
        std::cout << "action2" << std::endl;
    }
};

class MinhaEstrategia : public CAT::StrategySet {

public: 

    void create() {
        auto action1 = std::make_shared<Action1>();
        auto action2 = std::make_shared<Action2>();
        
        this->addAction(action1);
        this->addAction(action2);
    }
};