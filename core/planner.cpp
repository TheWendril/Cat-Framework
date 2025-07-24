#include "planner.hpp"

namespace CAT {

Planner::Planner() : Element() {}

void Planner::run() {
    if(this->action)
        this->action->act(this);
    this->notify();
}

void Planner::update() {
    this->run();
}

void Planner::publishStrategy(std::shared_ptr<CAT::Strategy> strategySet) {
    this->localKnowledge->setNextStrategy(strategySet);
}

}
