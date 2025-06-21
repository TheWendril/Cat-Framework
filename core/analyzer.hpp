// written by Wendril Avila

/*
    Main header for Cat Framework
    "Always make the simple as possible, evaluate, forward"
*/

#ifndef ANALYZER_HPP
#define ANALYZER_HPP

#include <iostream>
#include "element.hpp"
#include "constraintModel.hpp"

namespace CAT{

class Analyzer : public CAT::Element {

public:

    std::list<CAT::ConstraintModel> constraints{};

    void update(){
        this->run();
    }
    
    void verifyConstraints(){
        for(CAT::ConstraintModel& constraint : this->constraints){
            bool result = constraint.check(this->localKnowledge);
            if(!result){
                this->notify();
                break;
            }
        }
    }

}; 

} 

#endif