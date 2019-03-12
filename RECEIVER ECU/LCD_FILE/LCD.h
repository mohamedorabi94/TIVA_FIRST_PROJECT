/*
 * LCD.h
 *
 *  Created on: Mar 12, 2019
 *      Author: AVE-LAP-063
 */

#ifndef INCLUDE_LCD_H_
#define INCLUDE_LCD_H_

#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_memmap.h"
#include "driverlib/debug.h"
#include "driverlib/gpio.h"
#include "driverlib/sysctl.h"




extern uint8_t j;
    extern uint8_t i;
    extern uint8_t h;


void LCD_INIT(void);
void LCD_Send_Command (uint8_t cmd);
void LCD_displayChar (uint8_t data);
#define First_Bit 0x01
#define LCD_RS GPIO_PIN_2
#define LCD_RW GPIO_PIN_3
#define LCD_E GPIO_PIN_4
#define LCD_D4 GPIO_PIN_4
#define LCD_D5 GPIO_PIN_5
#define LCD_D6 GPIO_PIN_6
#define LCD_D7 GPIO_PIN_7
#define PORT1_LCD  GPIO_PORTA_BASE
#define PORT2_LCD  GPIO_PORTC_BASE
#define CMND1_4BITMODE 0X33
#define CMND2_4BITMODE 0x32
#define CMND3_4BITMODE 0X28
#define CURSOR_ON 0X0E
#define  CLEAR_LCD 0X01
#define FIRST_ROW 0x80
#define SECOND_ROW 0xC0
#define Get_Bit(Register,Bit)    (((Register&(1<<Bit))))
void LCD_Send_Data (uint8_t cmd);
#endif /* INCLUDE_LCD_H_ */
