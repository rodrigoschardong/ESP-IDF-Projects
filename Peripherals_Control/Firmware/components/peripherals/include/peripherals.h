#pragma once
#include <iostream>

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"
#include "esp_event.h"

#include "driver/gpio.h"

class cPeripheral{
    private:
        uint8_t gpio_num_;

    public:
        cPeripheral();
        ~cPeripheral();
        void ConfigurePeripheral(uint8_t gpio_num);
};
