// written by Wendril Avila

/*
    Main header for Cat Framework
    "Always make the simple as possible, evaluate, forward"
*/


#ifndef ACTIONHPP
#define ACTIONHPP

namespace CAT {

class Action
{
public:
    virtual void act() = 0;
    virtual ~Action() = default;
};

};

#endif