#pragma once
#include <iostream>

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"
#include "esp_event.h"

#include "peripherals.h"

class cGpioInput: public cPeripheral{
    private:
        uint8_t gpio_num_;

    public:
        cGpioInput();
        ~cGpioInput();
        void ConfigurePeripheral(uint8_t gpio_num);
};