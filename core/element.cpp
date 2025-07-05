#include "element.hpp"

namespace CAT {

Element::Element() : localKnowledge(nullptr), moduleKnowledge(nullptr), observer(nullptr), action(nullptr) {}

void Element::attach(CAT::Element* element) {
    this->observer = element;
}

void Element::setAction(CAT::Action& action) {
    this->action = &action;
}

void Element::run() {
    if(this->action) this->action->act(this);
    if(this->observer) this->observer->update();
}

CAT::Knowledge* Element::getLocalKnowledge() const { return localKnowledge; }
void Element::setLocalKnowledge(CAT::Knowledge *k) { localKnowledge = k; }
void Element::setModuleKnowledge(CAT::Knowledge *k) { moduleKnowledge = k; }

void Element::notify() {
    if (this->observer)
        this->observer->update();
}

}
