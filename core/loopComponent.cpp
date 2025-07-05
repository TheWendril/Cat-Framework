#include "loopComponent.hpp"

#ifdef ESP_PLATFORM
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#endif

namespace CAT {

#ifdef ESP_PLATFORM
static void loop_task(void* pvParameter) {
    CAT::LoopComponent* self = static_cast<CAT::LoopComponent*>(pvParameter);
    while (true) {
        printf("ESP LOOP\n");
        self->monitor.run();
        vTaskDelay(1); // Small delay for FreeRTOS
    }
}
#endif

LoopComponent::LoopComponent() : CompositeNode() {}

void LoopComponent::addMonitorAction(std::shared_ptr<CAT::Action> action) {
    this->monitor.setAction(*action);
    this->monitorActionPtr = action;
}

void LoopComponent::addPlannerAction(std::shared_ptr<CAT::Action> action) {
    this->planner.setAction(*action);
    this->plannerActionPtr = action;
}

void LoopComponent::addConstraint(std::shared_ptr<CAT::ConstraintModel> constraint) {
    this->analyzer.constraints.push_back(constraint.get());
    this->constraintPtrs.push_back(constraint);
}

void LoopComponent::init() {
    this->compositeNodeType = CAT::CompositeNodeType::MAPEK;
    this->monitor.attach(&this->analyzer);
    this->analyzer.attach(&this->planner);
    this->planner.attach(&this->executor);

    this->monitor.setModuleKnowledge(this->moduleComponent);
    this->analyzer.setModuleKnowledge(this->moduleComponent);
    this->planner.setModuleKnowledge(this->moduleComponent);
    this->executor.setModuleKnowledge(this->moduleComponent);

    this->monitor.setLocalKnowledge(this->knowledge);
    this->analyzer.setLocalKnowledge(this->knowledge);
    this->planner.setLocalKnowledge(this->knowledge);
    this->executor.setLocalKnowledge(this->knowledge);

#ifdef ESP_PLATFORM
    // ESP32: Use FreeRTOS task
    xTaskCreate(loop_task, "loop_task", 4096, this, 1, nullptr);
#else
    std::thread([this]() {
        while (true) {
            this->monitor.run();
        }
    }).detach();
#endif
}

} // namespace CAT
