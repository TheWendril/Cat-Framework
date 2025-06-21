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

    void update(){
        this->run();
    }
    
    void publishStrategy(CAT::Strategy& strategySet){
        this->localKnowledge->setNextStrategy(strategySet);
        this->notify();
    }

}; 

} 

#endif