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

class Monitor : public CAT::Element {

public:

    void run() {
        if(this->action)
            this->action->act(this);
        this->notify();
    }

    void update() override {
        // O update pode ser usado para receber notificações do ciclo
        std::cout << "Monitor recebeu update (pode re-coletar dados)" << std::endl;
    }

    void publishData(CAT::Model monitorData){
        this->localKnowledge->setCurrentState(monitorData);
    }
}; 

} 

#endif