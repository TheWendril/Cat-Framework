// written by Wendril Avila

#include "./app.hpp"

namespace CAT {

App::App(CAT::Module& newModule) : defaultModule(newModule) {}

void App::start() {
    this->defaultModule.init();

    while (true) {}
}

} // namespace CAT