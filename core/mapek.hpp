// written by Wendril Avila

/*
    Main header for Cat Framework
    "Always make the simple as possible, evaluate, forward"
*/

#ifndef MAPEK_HPP
#define MAKEK_HPP


#include <iostream>
#include "loopComponent.hpp"

namespace CAT{

class MAPEK : public LoopComponent{

public:

    virtual void configure() = 0;
}; 

} 

#endif