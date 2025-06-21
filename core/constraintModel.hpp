// written by Wendril Avila

/*
    Main header for Cat Framework
    "Always make the simple as possible, evaluate, forward"
*/

#ifndef CONSTRAINTMODEL_HPP
#define CONSTRAINTMODEL_HPP

#include <iostream>
#include "knowledge.hpp"

namespace CAT{

class ConstraintModel {

public:
    virtual bool check(Knowledge* knowledge) = 0;
}; 

} 

#endif