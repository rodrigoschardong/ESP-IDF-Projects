#pragma once

#include <iostream>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include "lwip/err.h"
#include "nvs_flash.h"

#include "peripherals.h"
#include "gpio_input.h"
#include "gpio_output.h"

#include "wifi.h"

class HelloCMake final
{
    public: void run(int i);
};