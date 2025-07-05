// written by Wendril Avila

/*
    Main header for Cat Framework
    "Always make the simple as possible, evaluate, forward"
*/

#ifndef ELEMENT_HPP
#define ELEMENT_HPP

#include <iostream>
#include "compositeNode.hpp"
#include "knowledge.hpp"

namespace CAT{

class Action;

class Element {
    
protected:

    CAT::Knowledge * localKnowledge;
    CAT::Knowledge * moduleKnowledge;
    CAT::Element * observer;
    CAT::Action* action;

    void notify();

public:

    Element();
    void attach(CAT::Element* element);
    virtual void update() = 0;
    void setAction(CAT::Action& action);
    virtual void run();
    CAT::Knowledge * getLocalKnowledge() const;
    void setLocalKnowledge(CAT::Knowledge *k);
    void setModuleKnowledge(CAT::Knowledge *k);
}; 

} 

#endif