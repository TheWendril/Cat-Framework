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
    std::list<std::shared_ptr<CAT::CompositeNode>> Childrens;

public:
    void init() override{
        this->compositeNodeType = CAT::CompositeNodeType::MODULE;

        for(const auto& children : this->Childrens){
            if(children) children->init();
        }

        std::cout << "ModularComponent" << std::endl;
    }

    void add(std::shared_ptr<CAT::CompositeNode> compositeNode){
        this->Childrens.push_back(compositeNode);
    }

    virtual void createModule() = 0;
}; 

} 

#endif