// written by Wendril Avila

/*
    Main header for Cat Framework
    "Always make the simple as possible, evaluate, forward"
*/

#ifndef EXECUTOR_HPP
#define EXECUTOR_HPP

#include <iostream>
#include "element.hpp"

namespace CAT{

class Executor : public CAT::Element {

public:


    void run() {
        CAT::StrategySet* strategySet = this->localKnowledge->getNextStrategy();
        if(strategySet) {
            for(const auto& action : strategySet->Actions){
                if(action) action->act(this);
            }
        }
    }

    void update() override {
        this->run();
    }

}; 

} 

#endif