// written by Wendril Avila

/*
    Main header for Cat Framework
    "Always make the simple as possible, evaluate, forward"
*/

#ifndef COMPOSITENODE_HPP
#define COMPOSITENODE_HPP

#include <iostream>
#include "knowledge.hpp"
#include "enum/compositeNodeType.hpp"

namespace CAT {

class CompositeNode {

public:

    CAT::Knowledge * knowledge;
    CAT::CompositeNodeType compositeNodeType;
    
    CompositeNode() {
        this->knowledge = new CAT::Knowledge();
    }

    virtual void init() = 0;
}; 


} 

#endif