#include <iostream>
#include "teste/knowledge.hpp"
#include "teste/model.hpp"


int main(){

    meuModel mdl;
    mdl.a = 10;
    CAT::Knowledge * mkn = new CAT::Knowledge();
    mkn->setCurrentState(mdl);
    meuModel * mdl2 = static_cast<meuModel*>(mkn->getCurrentState());
    std::cout << mdl2->a << std::endl;
    
}