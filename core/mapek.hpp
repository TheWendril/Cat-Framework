// written by Wendril Avila

/*
    Main header for Cat Framework
    "Always make the simple as possible, evaluate, forward"
*/

#ifndef MAPEK_HPP
#define MAKEK_HPP


#include <iostream>
#include "./utils/logs.hpp"

namespace CAT{

class MAPEK{

public:

    Monitor _Monitor{};
    Analyze _Analyze{};
    Planner _Planner{};
    Executor _Executor{};

    void run();
    void async_run();

    class MAPEKBuilder{

    }; // end of MAPEKBuilderClass

}; // end of MAPEK class



} // end of namespace

#endif