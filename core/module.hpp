// written by Wendril Avila

/*
    Main header for Cat Framework
    "Always make the simple as possible, evaluate, forward"
*/

#ifndef MODULE_HPP
#define MODULE_HPP

#include <iostream>
#include "modularComponent.hpp"

namespace CAT{

class Module : public CAT::ModularComponent{

public:
    virtual void createModule() = 0;
}; 

} 

#endif