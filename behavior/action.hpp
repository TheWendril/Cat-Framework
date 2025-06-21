#include "../core/model/action.hpp"

class MinhaAcao : public CAT::Action {

public:

    void act() override {
        std::cout << "Aqui é uma ação" << std::endl;
    }

};