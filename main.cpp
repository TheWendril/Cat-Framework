#include "core/app.hpp"
#include "modules/default.module.hpp"

int main(){

    DefaultModule mmdl;
    mmdl.createModule();
    
    CAT::App app(mmdl);
    app.start();
    
    return 0;
}