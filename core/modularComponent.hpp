// written by Wendril Avila

/*
    Main header for Cat Framework
    "Simplify. Evaluate. Move forward."
*/

#ifndef MODULARCOMPONENT_HPP
#define MODULARCOMPONENT_HPP


#include <iostream>
#include "compositeNode.hpp"

namespace CAT{

class ModularComponent : public CAT::CompositeNode {

private:
    std::list<std::shared_ptr<CAT::CompositeNode>> Childrens;

public:
    ModularComponent();
    virtual ~ModularComponent();
    void init() override;
    void add(std::shared_ptr<CAT::CompositeNode> compositeNode);
    virtual void createModule() = 0;
}; 

} 

#endif