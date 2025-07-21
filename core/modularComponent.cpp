// Implementation for ModularComponent
#include "modularComponent.hpp"

namespace CAT {

ModularComponent::ModularComponent() {}
ModularComponent::~ModularComponent() {}

void ModularComponent::init() {
    this->compositeNodeType = CAT::CompositeNodeType::MODULE;
    for(const auto& children : this->Childrens){
        if(children) children->init();
    }
}

void ModularComponent::add(std::shared_ptr<CAT::CompositeNode> compositeNode) {
    this->Childrens.push_back(compositeNode);
}

} // namespace CAT
