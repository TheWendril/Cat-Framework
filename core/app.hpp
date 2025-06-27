// written by Wendril Avila

/*
    Main header for Cat Framework
    "Always make the simple as possible, evaluate, forward"
*/

#ifndef APP_HPP
#define APP_HPP


#include <iostream>
#include "module.hpp"

namespace CAT {

class App {

public:

    CAT::Module& defaultModule;

    App(CAT::Module& newModule) : defaultModule(newModule){}

    void start(){
        this->defaultModule.init();
        
        while(true){};
    }
}; 

} 

#endif