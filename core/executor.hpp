// written by Wendril Avila

/*
    Main header for Cat Framework
    "Always make the simple as possible, evaluate, forward"
*/

#ifndef EXECUTOR_HPP
#define EXECUTOR_HPP

#include <iostream>
#include "element.hpp"

namespace CAT{

class Executor : public CAT::Element {

public:
    Executor();
    void run() override;
    void update() override;

}; 

} 

#endif