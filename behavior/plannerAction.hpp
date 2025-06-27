#include "../core/model/action.hpp"

class PlannerAction : public CAT::Action {
public:
    void act(CAT::Element* element) override {
        std::cout << "Planejando" << std::endl;
    }
};