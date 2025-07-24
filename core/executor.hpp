// written by Wendril Avila

/*
    Main header for Cat Framework
    "Simplify. Evaluate. Move forward."
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