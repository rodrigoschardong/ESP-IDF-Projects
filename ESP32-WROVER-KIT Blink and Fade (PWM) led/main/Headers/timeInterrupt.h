#pragma once

#include "driver/timer.h"

void IRAM_ATTR timer_group0_isr(void *para);
void tg0_timer0_init(void);