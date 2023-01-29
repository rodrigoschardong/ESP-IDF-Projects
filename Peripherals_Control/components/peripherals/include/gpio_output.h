#pragma once
#include <iostream>

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"
#include "esp_event.h"

#include "driver/gpio.h"

#include "peripherals.h"

class cGpioOutput: public cPeripheral{
    private:
        gpio_num_t gpio_num_;
        bool level_;
    public:
        cGpioOutput();
        ~cGpioOutput();
        void ConfigurePeripheral(uint8_t gpio_num);
        void WritePeripheral(bool level);
};