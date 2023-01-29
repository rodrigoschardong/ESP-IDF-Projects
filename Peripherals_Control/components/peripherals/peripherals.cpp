#include "peripherals.h"

#define TAG "[Peripheral] "

cPeripheral::cPeripheral(){
    
}
cPeripheral::~cPeripheral(){

}

void cPeripheral::ConfigurePeripheral(uint8_t gpio_num){
    gpio_num_ = gpio_num;
    std::cout << TAG << "New peripheral component on GPIO: " << (int)gpio_num <<  ".\n";
}

