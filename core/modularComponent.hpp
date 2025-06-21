// written by Wendril Avila

/*
    Main header for Cat Framework
    "Always make the simple as possible, evaluate, forward"
*/

#ifndef MODULARCOMPONENT_HPP
#define MODULARCOMPONENT_HPP


#include <iostream>
#include "compositeNode.hpp"

namespace CAT{

class ModularComponent : public CAT::CompositeNode {

private:

    std::list<CAT::CompositeNode> Childrens;

public:
    void init() override{
        this->compositeNodeType = CAT::CompositeNodeType::MODULE;
        std::cout << "ModularComponent" << std::endl;
    }

    void add(CAT::CompositeNode& compositeNode){
        this->Childrens.push_back(compositeNode);
    }

    virtual void createModule() = 0;
}; 

} 

#endif