#include <Cat/model/strategySet.hpp>
#include <Cat/model/action.hpp>
#include <fstream>
#include "../behavior/executor.action.hpp"

class DefaultStrategy : public CAT::Strategy {

public: 

    void create() override {
        auto action1 = std::make_shared<Action1>();
        auto action2 = std::make_shared<Action2>();
        
        this->addAction(action1);
        this->addAction(action2);
    }
};