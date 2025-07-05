#include "monitor.hpp"

namespace CAT {

Monitor::Monitor() : Element() {}

void Monitor::run() {
    if(this->action)
        this->action->act(this);
    this->notify();
}

void Monitor::update() {}

void Monitor::publishData(std::shared_ptr<CAT::Model> monitorData) {
    this->localKnowledge->setCurrentState(monitorData);
}

}
