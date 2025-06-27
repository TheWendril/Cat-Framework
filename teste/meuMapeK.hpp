#include "../core/mapek.hpp"

class MonitorAction : public CAT::Action {
public:
    void act(CAT::Element* element) override {
        std::cout << "Estou monitorando" << std::endl;
        // CAT::Model model;
        // element->getLocalKnowledge()->setCurrentState(model);
    }
};

class PlannerAction : public CAT::Action {
public:
    void act(CAT::Element* element) override {
        std::cout << "Estou Planejando" << std::endl;
        //std::cout << element->getLocalKnowledge()->getCurrentState() << std::endl;
    }
};

class AConstraint : public CAT::ConstraintModel {
public:
    bool check(CAT::Knowledge* knowledge) override {
        std::cout << "Analise 1" << std::endl;
        return false;
    }
};

class MMPK : public CAT::MAPEK {
public:
    MMPK(){
        this->configure();
    }

    void configure() override {
        auto monitorAction = std::make_shared<MonitorAction>();
        auto aConstraint = std::make_shared<AConstraint>();
        auto plannerAction = std::make_shared<PlannerAction>();
        this->addMonitorAction(monitorAction);
        this->addConstraint(aConstraint);
        this->addPlannerAction(plannerAction);
    }
};