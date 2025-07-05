#include "executor.hpp"

namespace CAT {

Executor::Executor() : Element() {}

void Executor::run() {
    CAT::Strategy* strategy = this->localKnowledge->getNextStrategy();
    if(strategy) {
        for(const auto& action : strategy->Actions){
            if(action) action->act(this);
        }
    }
}

void Executor::update() {
    this->run();
}

}
