// written by Wendril Avila

/*
    Main header for Cat Framework
    "Always make the simple as possible, evaluate, forward"
*/

#ifndef LOOPCOMPONENT_HPP
#define LOOPCOMPONENT_HPP

#include <iostream>
#include <memory>
#include <vector>
#include <thread>
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

private:
    std::shared_ptr<CAT::Action> monitorActionPtr;
    std::shared_ptr<CAT::Action> plannerActionPtr;
    std::vector<std::shared_ptr<CAT::ConstraintModel>> constraintPtrs;

public:
    LoopComponent();
    void init();
    void addMonitorAction(std::shared_ptr<CAT::Action> action);
    void addPlannerAction(std::shared_ptr<CAT::Action> action);
    void addConstraint(std::shared_ptr<CAT::ConstraintModel> constraint);

}; 

} 

#endif