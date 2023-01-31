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

void FlashInit(){
    esp_err_t ret = nvs_flash_init();
    if (ret == ESP_ERR_NVS_NO_FREE_PAGES || ret == ESP_ERR_NVS_NEW_VERSION_FOUND) {
      ESP_ERROR_CHECK(nvs_flash_erase());
      ret = nvs_flash_init();
    }
    ESP_ERROR_CHECK(ret);
}

extern "C" void app_main(void)
{
    cWiFi wifi("Dig-Fi", "trampolim");
    cGpioOutput gpio;

    FlashInit();

    gpio.ConfigurePeripheral(2);
    wifi.initStation();
    bool level = false;
    while(1){
        gpio.WritePeripheral(level);
        level = !level;
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}