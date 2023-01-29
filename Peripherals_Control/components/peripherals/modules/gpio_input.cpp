#include "gpio_input.h"

#define TAG "[Gpio] "

cGpioInput::cGpioInput(){

}

cGpioInput::~cGpioInput(){

}

void cGpioInput::ConfigurePeripheral(uint8_t gpio_num){
    gpio_num_ = gpio_num;
    std::cout << TAG << "New gpio component on GPIO: " << (int)gpio_num <<  ".\n";
}
