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


    void update(){
        std::list<CAT::Action> actions = this->localKnowledge->getNextStrategy().Actions;

        for(CAT::Action& action : actions){
            action.act();
        }
    }

}; 

} 

#endif