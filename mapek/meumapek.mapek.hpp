#include "../core/mapek.hpp"
#include "../behavior/monitorAction.hpp"
#include "../constraint/minhaconstraint.hpp"
#include "../behavior/plannerAction.hpp"

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