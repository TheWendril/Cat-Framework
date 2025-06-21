// written by Wendril Avila

/*
    Main header for Cat Framework
    "Always make the simple as possible, evaluate, forward"
*/


#ifndef STRATEGYSETHPP
#define STRATEGYSETHPP

#include "action.hpp"
#include <list>
#include <memory>

namespace CAT {

class StrategySet
{
public:
    std::list<std::shared_ptr<CAT::Action>> Actions;

    void addAction(std::shared_ptr<CAT::Action> action){
        this->Actions.push_back(action);
    }

    virtual void create() = 0;
    
    virtual ~StrategySet() = default;

};


};

#endif