#include "analyzer.hpp"

namespace CAT {

void Analyzer::run() {
    this->verifyConstraints();
}

void Analyzer::update() {
    this->run();
}

void Analyzer::verifyConstraints() {
    for(CAT::ConstraintModel* constraint : this->constraints){
        bool result = constraint->check(this->localKnowledge);
        if(!result){
            this->notify();
            break;
        }
    }
}

}
