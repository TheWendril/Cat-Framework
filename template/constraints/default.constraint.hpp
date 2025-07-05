#include <Cat/constraintModel.hpp>

class AConstraint : public CAT::ConstraintModel {
public:
    bool check(CAT::Knowledge* knowledge) override {
        printf("Analyzing\n");
        return false;
    }
};