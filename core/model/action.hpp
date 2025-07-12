// written by Wendril Avila

/*
    Main header for Cat Framework
    "Always make the simple as possible, evaluate, forward"
*/


#ifndef ACTIONHPP
#define ACTIONHPP

namespace CAT {

class Element; 

class Action
{
public:
    virtual void act(CAT::Element* element) = 0;
    virtual ~Action() = default;
};

};

#endif