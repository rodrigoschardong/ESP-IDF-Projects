//https://embeddedtutorials.com/eps32/esp-idf-cpp-with-cmake-for-esp32/

#include <iostream>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include "main.h"
//#include "peripherals.h"
//#include "gpios.h"

void HelloCMake::run(int i)
{
    std::cout << "Hello World from C++ "<< i << '\n';
    vTaskDelay(pdMS_TO_TICKS(1000));
}

extern "C" void app_main(void)
{
    cGpioOutput gpio;
    gpio.ConfigurePeripheral(2);
    bool level = false;
    while(1){
        gpio.WritePeripheral(level);
        level = !level;
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}