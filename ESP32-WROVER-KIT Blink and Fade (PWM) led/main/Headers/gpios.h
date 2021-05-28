#pragma once
#include "driver/ledc.h"

void ChangeLeds(void);
void Configure_Leds(void);
void ChangeFade(uint32_t ledcFadeTime);
void LedcConfig();