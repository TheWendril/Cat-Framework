class Action1 : public CAT::Action {

public:
    void act(CAT::Element * element) override {
        printf("Action1\n");
    }
};

class Action2 : public CAT::Action {

public:
    void act(CAT::Element * element) override {
        printf("Action2\n");
    }
};
