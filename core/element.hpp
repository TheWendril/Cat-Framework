// written by Wendril Avila

/*
    Main header for Cat Framework
    "Always make the simple as possible, evaluate, forward"
*/

#ifndef ELEMENT_HPP
#define ELEMENT_HPP

#include <iostream>
#include "compositeNode.hpp"

namespace CAT{

class Element {

private:
    CAT::Element * observer;
    CAT::Action& action;

protected:

    void notify(){
        if (this->observer)
            this->observer->update();
    }

public:

    CAT::Knowledge * localKnowledge;
    CAT::Knowledge * moduleKnowledge;

    void attach(CAT::Element* element){
        this->observer = element;
    }

    virtual void update() = 0;

    void setAction(CAT::Action& action){
        this->action = action;
    }

    void run() {
        this->action.act();
    }
}; 

} 

#endif