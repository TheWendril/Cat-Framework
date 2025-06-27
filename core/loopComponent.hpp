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

    LoopComponent() {
        this->moduleComponent= new CAT::Knowledge();
    }

    void addMonitorAction(std::shared_ptr<CAT::Action> action){
        this->monitor.setAction(*action);
        this->monitorActionPtr = action;
    }

    void addPlannerAction(std::shared_ptr<CAT::Action> action){
        this->planner.setAction(*action);
        this->plannerActionPtr = action;
    }

    void addConstraint(std::shared_ptr<CAT::ConstraintModel> constraint){
        this->analyzer.constraints.push_back(constraint.get());
        this->constraintPtrs.push_back(constraint);
    }

private:
    std::shared_ptr<CAT::Action> monitorActionPtr;
    std::shared_ptr<CAT::Action> plannerActionPtr;
    std::vector<std::shared_ptr<CAT::ConstraintModel>> constraintPtrs;

public:

    void init() {
        this->compositeNodeType = CAT::CompositeNodeType::MAPEK;

        this->monitor.attach(&this->analyzer);
        this->analyzer.attach(&this->planner);
        this->planner.attach(&this->executor);

        this->monitor.moduleKnowledge = this->moduleComponent;
        this->analyzer.moduleKnowledge = this->moduleComponent;
        this->planner.moduleKnowledge = this->moduleComponent;
        this->executor.moduleKnowledge = this->moduleComponent;

        this->monitor.localKnowledge = &this->knowledge;
        this->analyzer.localKnowledge = &this->knowledge;
        this->planner.localKnowledge = &this->knowledge;
        this->executor.localKnowledge = &this->knowledge;


        std::thread([this]() {
            while(true) {
                this->monitor.run();
            }
        }).detach();
    }

}; 

} 

#endif