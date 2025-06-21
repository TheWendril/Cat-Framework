// written by Wendril Avila

/*
    Main header for Cat Framework
    "Always make the simple as possible, evaluate, forward"
*/

#ifndef MONITOR_HPP
#define MONITOR_HPP

#include <iostream>
#include "element.hpp"

namespace CAT{

class Monitor : public CAT::Element{

public:
    void update(){
        std::cout << "monitoring" << std::endl;
    }

    void publishData(CAT::Model monitorData){
        this->localKnowledge->setCurrentState(monitorData);
    }
}; 

} 

#endif