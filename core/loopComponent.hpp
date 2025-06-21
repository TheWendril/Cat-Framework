// written by Wendril Avila

/*
    Main header for Cat Framework
    "Always make the simple as possible, evaluate, forward"
*/

#ifndef LOOPCOMPONENT_HPP
#define LOOPCOMPONENT_HPP

#include <iostream>
#include "compositeNode.hpp"
#include "monitor.hpp"
#include "analyzer.hpp"
#include "planner.hpp"
#include "executor.hpp"

namespace CAT{

class LoopComponent : public CAT::CompositeNode {

protected:
    CAT::Knowledge * moduleComponent;
    CAT::Monitor monitor;
    CAT::Analyzer analyzer;
    CAT::Planner planner;
    CAT::Executor executor;

    void addMonitorAction(CAT::Action& action){
        this->monitor.setAction(action);
    }

    void addPlannerAction(CAT::Action& action){
        this->planner.setAction(action);
    }

    void addConstraint(CAT::ConstraintModel& constraint){
        this->analyzer.constraints.push_back(constraint);
    }

public:

    void init() {
        this->compositeNodeType = CAT::CompositeNodeType::MAPEK;

        this->monitor.attach(&this->analyzer);
        this->analyzer.attach(&this->planner);
        this->planner.attach(&this->executor);
    }

}; 

} 

#endif