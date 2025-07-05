#include "Cat/model/action.hpp"
#include <fstream>
#include "../models/fan.model.hpp"

class MonitorAction : public CAT::Action {

public:

    void act(CAT::Element * element) override {
        std::cout << "Monitoring" << std::endl;
    }

};