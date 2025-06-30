// written by Wendril Avila

/*
    Main header for Cat Framework
    "Always make the simple as possible, evaluate, forward"
*/

#ifndef PLANNER_HPP
#define PLANNER_HPP

#include <iostream>
#include "element.hpp"

namespace CAT{

class Planner : public CAT::Element {

public:

    void run() {
        // Executa a ação de planejamento
        if(this->action)
            this->action->act(this);
        // Após planejar, notifica o Executor
        this->notify();
    }

    void update() override {
        this->run();
    }
    
    void publishStrategy(std::shared_ptr<CAT::Strategy> strategySet){
        this->localKnowledge->setNextStrategy(strategySet);
        this->notify();
    }

}; 

} 

#endif