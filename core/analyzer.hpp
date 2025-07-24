// written by Wendril Avila

/*
    Main header for Cat Framework
    "Simplify. Evaluate. Move forward."
*/

#ifndef ANALYZER_HPP
#define ANALYZER_HPP

#include <iostream>
#include <list>
#include "element.hpp"
#include "constraintModel.hpp"

namespace CAT {

class Analyzer : public CAT::Element {
public:
    std::list<CAT::ConstraintModel*> constraints{};
    void run() override;
    void update() override;
    void verifyConstraints();
};

}

#endif