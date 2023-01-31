#include "gpio_output.h"

#define TAG "[Gpio] "

cGpioOutput::cGpioOutput(){

}

cGpioOutput::~cGpioOutput(){

}

void cGpioOutput::ConfigurePeripheral(uint8_t gpio_num){
    gpio_num_ = (gpio_num_t)gpio_num;
    std::cout << TAG << "New gpio component on GPIO output: " << (int)gpio_num <<  ".\n";
    gpio_set_direction(gpio_num_, GPIO_MODE_OUTPUT);
}

void cGpioOutput::WritePeripheral(bool level){
    level_ = level;
    gpio_set_level(gpio_num_, level);
    std::cout << TAG << "Gpio" << (int)gpio_num_ << " has been " << ((level)?"On":"Off") <<  ".\n";
}