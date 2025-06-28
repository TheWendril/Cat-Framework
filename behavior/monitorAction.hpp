#include "../core/model/action.hpp"
#include <fstream>
#include "../models/ventilador.model.hpp"

class MonitorAction : public CAT::Action {

public:

    void act(CAT::Element * element) override {
        std::fstream sensor("sensor.txt");
        std::fstream motor("motor.txt");

        
        std::string sensorRead;
        std::getline(sensor, sensorRead);

        std::string motorRead;
        std::getline(motor, motorRead);

        auto a = std::make_shared<Ventilador>();
        a->power = std::stoi(motorRead);
        a->temperature = std::stoi(sensorRead);

        element->getLocalKnowledge()->setCurrentState(a);

        std::cout << "Monitorando" << std::endl;
    }

};