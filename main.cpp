#include "core/app.hpp"
#include "modules/meumodulo.module.hpp"

int main(){

    MeuModulo mmdl;

    CAT::App app(mmdl);
    app.start();
    
    return 0;
}