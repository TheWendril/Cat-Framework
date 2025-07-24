#include "knowledge.hpp"

namespace CAT {

void Knowledge::setScopeModel(CAT::Model model) {
    this->ScopeModel = model;
}

CAT::Model Knowledge::getScopeModel() {
    return this->ScopeModel;
}

void Knowledge::setCurrentState(std::shared_ptr<CAT::Model> model) {
    this->DataHistory.push_front(model);
    if(this->DataHistory.size() > this->DataHistorySize)
        this->DataHistory.pop_back();
    this->CurrentState = model;
}

CAT::Model* Knowledge::getCurrentState() {
    return this->CurrentState.get();
}

std::list<std::shared_ptr<CAT::Model>> Knowledge::getDataHistory() {
    return this->DataHistory;
}

void Knowledge::setNextStrategy(std::shared_ptr<CAT::Strategy> strategy) {
    this->NextStrategy = strategy;
}

std::shared_ptr<CAT::Strategy> Knowledge::getNextStrategy() {
    return this->NextStrategy;
}

}
