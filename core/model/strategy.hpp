// written by Wendril Avila

/*
    Main header for Cat Framework
    "Simplify. Evaluate. Move forward."
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