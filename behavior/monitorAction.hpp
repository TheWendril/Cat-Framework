#include "../core/model/action.hpp"

class MonitorAction : public CAT::Action {

public:

    void act(CAT::Element * element) override {
        std::cout << "Monitorando" << std::endl;
    }

};