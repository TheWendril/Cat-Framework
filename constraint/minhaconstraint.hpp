#include "../core/constraintModel.hpp"

class AConstraint : public CAT::ConstraintModel {
public:
    bool check(CAT::Knowledge* knowledge) override {
        std::cout << "Analisando: Analise 1" << std::endl;
        return false;
    }
};