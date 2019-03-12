/*
 * UART.h
 *
 *  Created on: Mar 12, 2019
 *      Author: AVE-LABS-50
 */

#ifndef UART_H_
#define UART_H_

#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include "inc/hw_memmap.h"
#include "inc/hw_uart.h"
#include "inc/hw_types.h"
#include "driverlib/fpu.h"
#include "driverlib/gpio.h"
#include "driverlib/pin_map.h"
#include "driverlib/rom.h"
#include"driverlib/lcd.h"
#include "driverlib/rom_map.h"
#include "driverlib/sysctl.h"
#include "driverlib/uart.h"

#define NUM_0 0
#define NUM_1 1
#define NUM_2 2
#define NUM_3 3
#define NUM_4 4
#define NUM_5 5
#define NUM_6 6
#define NUM_7 7
#define NUM_8 8
#define NUM_9 9
#define NUM_10 10
#define NUM_30 30

#define ZeroAscii  0x30
/************************************************************************/
/* FUNCTION NAME: UART_INIT                                             */
/* @Param: void                                                         */
/* return: void                                                         */
/* FUNCTION Description: Initialization of UART                         */
/************************************************************************/
void UART5_INIT(void);


/************************************************************************/
/* FUNCTION NAME: UART_RecieveChar                                      */
/* @Param: void                                                         */
/* return: receive the data                                             */
/* FUNCTION Description: Receive data                                   */
/************************************************************************/
uint8_t UART5_RecieveChar(void);

#endif /* UART_H_ */
