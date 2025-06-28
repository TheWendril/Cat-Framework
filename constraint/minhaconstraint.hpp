#include "../core/constraintModel.hpp"

class AConstraint : public CAT::ConstraintModel {
public:
    bool check(CAT::Knowledge* knowledge) override {

        auto* ventilador = dynamic_cast<Ventilador*>(knowledge->getCurrentState());

        std::cout << "Analisando: Analise 1" << std::endl;

        if(ventilador->temperature > 40)
            return false;

        return true;
    }
};