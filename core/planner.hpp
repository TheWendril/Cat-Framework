// written by Wendril Avila

/*
    Main header for Cat Framework
    "Always make the simple as possible, evaluate, forward"
*/

#ifndef PLANNER_HPP
#define PLANNER_HPP

#include <iostream>
#include "element.hpp"

namespace CAT{

class Planner : public CAT::Element {

public:
    Planner();
    void run() override;
    void update() override;
    void publishStrategy(std::shared_ptr<CAT::Strategy> strategySet);

}; 

} 

#endif