#include <Cat/app.hpp>
#include "modules/default.module.hpp"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"

extern "C" void app_main() {
    DefaultModule defaultModule;
    defaultModule.createModule();

    CAT::App app(defaultModule);
    app.start();
}
