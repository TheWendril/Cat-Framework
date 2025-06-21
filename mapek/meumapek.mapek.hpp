#include "../core/mapek.hpp"

class meumapek : public CAT::MAPEK {

public:

    void configure() override {
        std::cout << "construindo um mape-k" << std::endl;
    }
};