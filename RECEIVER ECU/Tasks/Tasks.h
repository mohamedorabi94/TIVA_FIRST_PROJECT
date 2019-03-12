/*
 * Tasks.h
 *
 * Created: 2/23/2019 3:28:25 PM
 *  Author: AVE-LAP-032
 */ 


#ifndef TASKS_H_
#define TASKS_H_


#include "BitwiseOperations.h"
#include "Timer.h"
#include "LCD_FILE/Magic_Num.h"
//#include "Keypad_FILE/Keypad.h"
#include "UART_FILE/UART.h"

#include"LCD_FILE/LCD.h"

#define MAX_NO_OF_TASKS 4



/*************************LCD_inti()*********************
*Parameters :
*           I/P:
*           O/P:
*           I/P:
*Return:void
*Description: Function init is to Initialize the configuration
of LCD to determine whether four bits or eight bits
and also set cursor

********************************************************/
void LCD_INIT(void);
/*************************LCD_sendCommand()*********************
*Parameters :
*           I/P:
*           O/P:
*           I/P:
*Return:
*Description: SEND COMMAND TO KCD
********************************************************/
void KTR(void);

#endif /* TASKS_H_ */
