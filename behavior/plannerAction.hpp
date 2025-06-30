#include "../core/model/action.hpp"
#include "../strategy/minhaestrategia.hpp"

class PlannerAction : public CAT::Action {
public:
    void act(CAT::Element* element) override {

        auto strategy = std::make_shared<MinhaEstrategia>();
        strategy->create();
        element->localKnowledge->setNextStrategy(strategy);
        std::cout << "Planejando" << std::endl;
    }
};