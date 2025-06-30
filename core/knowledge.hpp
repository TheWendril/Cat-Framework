// written by Wendril Avila

/*
    Main header for Cat Framework
    "Always make the simple as possible, evaluate, forward"
*/

#ifndef KNOWLEDGE_HPP
#define KNOWLEDGE_HPP


#include <iostream>
#include "model/model.hpp"
#include "model/strategy.hpp"

namespace CAT{

class Knowledge {

private:

    CAT::Model ScopeModel;
    std::shared_ptr<CAT::StrategySet> NextStrategy;
    std::shared_ptr<CAT::Model> CurrentState;
    std::list<std::shared_ptr<CAT::Model>> DataHistory;
    int DataHistorySize = 100;

public:
    
    void setScopeModel(CAT::Model model){
        this->ScopeModel = model;
    }

    CAT::Model getScopeModel(){
        return this->ScopeModel;
    }

    void setCurrentState(std::shared_ptr<CAT::Model> model) {
        this->DataHistory.push_front(model);

        if(this->DataHistory.size() > this->DataHistorySize)
            this->DataHistory.pop_back();

        this->CurrentState = model;
    }

    CAT::Model* getCurrentState() {
        return this->CurrentState.get();
    }

    std::list<std::shared_ptr<CAT::Model>> getDataHistory() {
        return this->DataHistory;
    }

    void setNextStrategy(std::shared_ptr<CAT::StrategySet> strategy) {
        this->NextStrategy = strategy;
    }

    CAT::StrategySet* getNextStrategy() {
        return this->NextStrategy.get();
    }
    
}; 

} 

#endif