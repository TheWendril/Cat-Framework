// written by Wendril Avila

/*
    Main header for Cat Framework
    "Simplify. Evaluate. Move forward."
*/

#ifndef KNOWLEDGE_HPP
#define KNOWLEDGE_HPP


#include <iostream>
#include <list>
#include <memory>
#include "model/model.hpp"
#include "model/strategy.hpp"

namespace CAT {

class Knowledge {
private:
    CAT::Model ScopeModel;
    std::shared_ptr<CAT::Strategy> NextStrategy;
    std::shared_ptr<CAT::Model> CurrentState;
    std::list<std::shared_ptr<CAT::Model>> DataHistory;
    int DataHistorySize = 10;
public:
    void setScopeModel(CAT::Model model);
    CAT::Model getScopeModel();
    void setCurrentState(std::shared_ptr<CAT::Model> model);
    std::shared_ptr<CAT::Model> getCurrentState();
    std::list<std::shared_ptr<CAT::Model>> getDataHistory();
    void setNextStrategy(std::shared_ptr<CAT::Strategy> strategy);
    std::shared_ptr<CAT::Strategy> getNextStrategy();
};

}

#endif