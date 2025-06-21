// written by Wendril Avila

/*
    Main header for Cat Framework
    "Always make the simple as possible, evaluate, forward"
*/


#ifndef STRATEGYHPP
#define STRATEGYHPP

#include "strategySet.hpp"
#include <list>

namespace CAT {

class Strategy : public CAT::StrategySet {

public:

    virtual void create() = 0;

};


};

#endif