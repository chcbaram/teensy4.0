/*
 * bsp.c
 *
 *  Created on: Dec 6, 2020
 *      Author: baram
 */


#include "bsp.h"


volatile uint32_t systick_time = 0;


void SysTick_Handler(void)
{
  systick_time++;
}


void bspInit(void)
{
  BOARD_InitPins();
  BOARD_InitBootClocks();
  BOARD_InitBootPeripherals();


  SysTick_Config(SystemCoreClock / 1000);
}

void delay(uint32_t ms)
{
#ifdef _USE_HW_RTOS
  if (xTaskGetSchedulerState() != taskSCHEDULER_NOT_STARTED)
  {
    osDelay(ms);
  }
  else
  {
    HAL_Delay(ms);
  }
#else
  uint32_t pre_time = systick_time;

  while(systick_time-pre_time < ms);
#endif
}

uint32_t millis(void)
{
  return systick_time;
}

