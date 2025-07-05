// written by Wendril Avila

/*
    Main header for Cat Framework
    "Always make the simple as possible, evaluate, forward"
*/

#ifndef MONITOR_HPP
#define MONITOR_HPP

#include <iostream>
#include "element.hpp"

namespace CAT{

class Monitor : public CAT::Element {

public:

    Monitor();

    void run() override;

    void update() override;

    void publishData(std::shared_ptr<CAT::Model> monitorData);
}; 

} 

#endif