#include <Cat/model/action.hpp>
#include "../strategy/default.strategyset.hpp"

class PlannerAction : public CAT::Action {
public:
    void act(CAT::Element* element) override {
        printf("Planning\n");
    }
};