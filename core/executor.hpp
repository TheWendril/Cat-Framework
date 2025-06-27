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
        CAT::Strategy* strategy = this->localKnowledge->getNextStrategy();
        if(strategy) {
            for(const auto& action : strategy->Actions){
                if(action) action->act(this);
            }
        }
    }

    void update() override {
        std::cout << "Executor" << std::endl;
        //this->run();
    }

}; 

} 

#endif