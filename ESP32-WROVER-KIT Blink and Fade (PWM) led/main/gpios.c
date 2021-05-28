//========================================================
//Extern Files
#include "gpios.h"

//========================================================
//Libs

//========================================================
//APIs
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "driver/ledc.h"    //Get Ledc

//========================================================
//DEFINES
#define RGB_RED_LED GPIO_NUM_0
#define RGB_GREEN_LED GPIO_NUM_2
#define RGB_BLUE_LED GPIO_NUM_4

//========================================================
//Vars
bool statusLed;
bool statusDutyC = false;
uint32_t dutyC = 0;

//========================================================
//Internal Functions

void ChangeDutyC(){
    if(statusDutyC){
        dutyC = 8000;
    }
    else{
        dutyC = 0;
    }
    statusDutyC = !statusDutyC;
}

//========================================================
//External Functions
void ChangeLeds(){
    //gpio_set_level(RGB_RED_LED,!statusLed);
    gpio_set_level(RGB_GREEN_LED,statusLed);
    statusLed = !statusLed;
}

void Configure_Leds(){
    gpio_set_direction(RGB_RED_LED, GPIO_MODE_OUTPUT);
    gpio_set_direction(RGB_GREEN_LED, GPIO_MODE_OUTPUT);

    statusLed = false;
    gpio_set_level(RGB_RED_LED,statusLed);
    gpio_set_level(RGB_GREEN_LED,!statusLed);
    ChangeLeds();
}

void ChangeFade(uint32_t ledcFadeTime){
    ledc_set_fade_with_time(LEDC_LOW_SPEED_MODE,
            LEDC_CHANNEL_3, dutyC, ledcFadeTime);
    ledc_fade_start(LEDC_LOW_SPEED_MODE,
            LEDC_CHANNEL_3, LEDC_FADE_NO_WAIT);
    ChangeDutyC();
}

void LedcConfig(){
    ledc_timer_config_t ledc_timer = {
        .duty_resolution = LEDC_TIMER_13_BIT, // resolution of PWM duty
        .freq_hz = 5000,                      // frequency of PWM signal
        .speed_mode = LEDC_LOW_SPEED_MODE,    // timer mode
        .timer_num = LEDC_TIMER_0,            // timer index
        .clk_cfg = LEDC_AUTO_CLK,             // Auto select the source clock
    };
    // Set configuration of timer0 for high speed channels
    ledc_timer_config(&ledc_timer);

    ledc_channel_config_t ledc_channel = {
            .channel    = LEDC_CHANNEL_3,
            .duty       = 0,
            .gpio_num   = RGB_BLUE_LED,
            .speed_mode = LEDC_LOW_SPEED_MODE,
            .hpoint     = 0,
            .timer_sel  = LEDC_TIMER_0,
        };
    ledc_channel_config(&ledc_channel);
    ledc_fade_func_install(0);
}
