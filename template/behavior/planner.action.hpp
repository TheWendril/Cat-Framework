#include <Cat/model/action.hpp>
#include "../strategy/default.strategyset.hpp"

class PlannerAction : public CAT::Action {
public:
    void act(CAT::Element* element) override {
        
        auto strategy = std::make_shared<DefaultStrategy>();
        strategy->create();
        element->getLocalKnowledge()->setNextStrategy(strategy);
        
        printf("Planning\n");
    }
};