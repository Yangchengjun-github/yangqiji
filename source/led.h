#ifndef _LED_H
#define _LED_H

#include "main.h"

#define LED1_ON _pc0  = 0
#define LED1_OFF _pc0 = 1

#define LED2_ON _pc1 = 0
#define LED2_OFF _pc1 = 1

#define LED3_ON _pc2 = 0
#define LED3_OFF _pc2 = 1

#define LED4_ON _pa0 = 0
#define LED4_OFF _pa0 = 1

#define LED5_ON _pa1 = 0
#define LED5_OFF _pa1 = 1

#define LED6_ON _pa2 = 0
#define LED6_OFF _pa2 = 1

#define LED1_TOGGLE _pc0 = !_pc0
#define LED2_TOGGLE _pc1 = !_pc1
#define LED3_TOGGLE _pc2 = !_pc2
#define LED4_TOGGLE _pa0 = !_pa0
#define LED5_TOGGLE _pa1 = !_pa1
#define LED6_TOGGLE _pa2 = !_pa2

#define LED_SYS 
#define LED_CONTINUE
#define LED_PULSE

void task_led(void);
void led_init(void);
void breath(void);
#endif
