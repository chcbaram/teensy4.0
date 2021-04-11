/*
 * bsp.h
 *
 *  Created on: Dec 6, 2020
 *      Author: baram
 */

#ifndef SRC_BSP_BSP_H_
#define SRC_BSP_BSP_H_


#include "def.h"


#define _USE_LOG_PRINT    1

#if _USE_LOG_PRINT
#define logPrintf(fmt, ...)     printf(fmt, ##__VA_ARGS__)
#else
#define logPrintf(fmt, ...)
#endif


#define BOARD_FLASH_SIZE        (2*1024*1024)


#include "config/board/clock_config.h"
#include "config/board/peripherals.h"
#include "config/board/pin_mux.h"


#include "fsl_gpio.h"


void bspInit(void);

void delay(uint32_t ms);
uint32_t millis(void);



#endif /* SRC_BSP_BSP_H_ */
