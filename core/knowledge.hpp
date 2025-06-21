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
    CAT::Strategy* NextStrategy;
    CAT::Model* CurrentState;
    std::list<CAT::Model> DataHistory;
    int DataHistorySize = 100;

public:
    
    void setScopeModel(CAT::Model model){
        this->ScopeModel = model;
    }

    CAT::Model getScopeModel(){
        return this->ScopeModel;
    }

    void setCurrentState(CAT::Model& model){
        this->DataHistory.push_front(model);

        if(this->DataHistory.size() > this->DataHistorySize)
            this->DataHistory.pop_back();

        this->CurrentState = &model;
    }

    CAT::Model* getCurrentState(){
        return this->CurrentState;
    }

    std::list<CAT::Model> getDataHistory(){
        return this->DataHistory;
    }

    void setNextStrategy(CAT::Strategy& strategy){
        this->NextStrategy = &strategy;
    }

    CAT::Strategy* getNextStrategy(){
        return this->NextStrategy;
    }
    
}; 

} 

#endif