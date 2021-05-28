/* WiFi softAP Example

   This example code is in the Public Domain (or CC0 licensed, at your option.)

   Unless required by applicable law or agreed to in writing, this
   software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
   CONDITIONS OF ANY KIND, either express or implied.
*/

//========================================================
//Libs


//========================================================
//Other files

#include "timeInterrupt.h"
#include "gpios.h"


//========================================================
//APIs
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"    //Get pin defines
#include "driver/timer.h"   //Get timer defines
#include "driver/ledc.h"
//========================================================
//DEFINES

//PINs
#define RED_LED_PIN         GPIO_NUM_0
#define GREEN_LED_PIN       GPIO_NUM_2
#define BLUE_LED_PIN        GPIO_NUM_4

//Timers
#define TIMER_INTR_SEL TIMER_INTR_LEVEL                                  // Timer level interrupt
#define TIMER_GROUP    TIMER_GROUP_0                                     // Test on timer group 0 
#define TIMER_DIVIDER   80                                               // Hardware timer clock divider, 80 to get 1MHz clock to timer
#define TIMER_SCALE    (TIMER_BASE_CLK / TIMER_DIVIDER)                  // Used to calculate counter value 
#define TIMER_FINE_ADJ   (0*(TIMER_BASE_CLK / TIMER_DIVIDER)/1000000)    // Used to compensate alarm value
#define TIMER_INTERVAL0_SEC   (0.5)                                      // Test interval for timer 0

//========================================================
//Globals
bool statusLed;

//========================================================
//Constants


//========================================================
//Prototypes


//========================================================
//Functions


void app_main()
{
    Configure_Leds();
    LedcConfig();
    tg0_timer0_init();
}