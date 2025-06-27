#include "core/app.hpp"
#include "modules/default.module.hpp"

int main(){

    DefaultModule defaultModule;
    defaultModule.createModule();
    
    CAT::App app(defaultModule);
    app.start();
    
    return 0;
}