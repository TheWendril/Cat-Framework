// written by Wendril Avila

/*
    Main header for Cat Framework
    "Simplify. Evaluate. Move forward."
*/

#ifndef APP_HPP
#define APP_HPP


#include <iostream>
#include "module.hpp"

namespace CAT {

class App {

public:

    CAT::Module& defaultModule;

    App(CAT::Module& newModule);
    void start();
}; 

} 

#endif