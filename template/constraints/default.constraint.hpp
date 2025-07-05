#include <Cat/constraintModel.hpp>

class AConstraint : public CAT::ConstraintModel {
public:
    bool check(CAT::Knowledge* knowledge) override {
        std::cout << "Analyzing" << std::endl;
        return false;
    }
};