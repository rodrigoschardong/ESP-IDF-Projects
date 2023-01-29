#pragma once

#include <iostream>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include "peripherals.h"
#include "gpio_input.h"
#include "gpio_output.h"

class HelloCMake final
{
    public: void run(int i);
};