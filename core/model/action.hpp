// written by Wendril Avila

/*
    Main header for Cat Framework
    "Simplify. Evaluate. Move forward."
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