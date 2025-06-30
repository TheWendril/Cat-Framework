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

    CAT::Element * observer;
    CAT::Action* action;
    int timeOut = 0;

    void notify(){
        if (this->observer)
            this->observer->update();
    }

public:

    CAT::Knowledge * localKnowledge;
    CAT::Knowledge * moduleKnowledge;

    Element() : localKnowledge(nullptr), moduleKnowledge(nullptr), observer(nullptr), action(nullptr) {
        this->localKnowledge = new CAT::Knowledge();
    }

    void attach(CAT::Element* element){
        this->observer = element;
    }
    virtual void update() = 0;
    void setAction(CAT::Action& action){
        this->action = &action;
    }
    void run() {
        if(this->action) this->action->act(this);
        if(this->observer) this->observer->update();
    }
    CAT::Knowledge * getLocalKnowledge() const { return localKnowledge; }
    void setLocalKnowledge(CAT::Knowledge *k) { localKnowledge = k; }
}; 

} 

#endif