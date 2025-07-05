class Action1 : public CAT::Action {

public:
    void act(CAT::Element * element) override {
        std::cout << "Action1" << std::endl;
    }
};

class Action2 : public CAT::Action {

public:
    void act(CAT::Element * element) override {
        std::cout << "Action2" << std::endl;
    }
};
