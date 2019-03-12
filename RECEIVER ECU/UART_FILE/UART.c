/*
 * UART.c
 *
 *  Created on: Mar 12, 2019
 *      Author: AVE-LABS-50
 */

#include "UART_FILE/UART.h"

/************************************************************************/
/* FUNCTION NAME: UART_INIT                                             */
/* @Param: void                                                         */
/* return: void                                                         */
/* FUNCTION Description: Initialization of UART                         */
/************************************************************************/
void UART5_INIT(void)
{



    /* Enable the GPIO port A */

        SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOE);
    /* Enable the UART0 module */

    SysCtlPeripheralEnable(SYSCTL_PERIPH_UART5);

   /* Set GPIO A0 and A1 as UART pins */

      GPIOPinConfigure(GPIO_PE4_U5RX);
      GPIOPinConfigure(GPIO_PE5_U5TX);
      GPIOPinTypeUART(GPIO_PORTE_BASE, GPIO_PIN_4 | GPIO_PIN_5);

    /* Wait for the UART0 module to be ready */

    while(!SysCtlPeripheralReady(SYSCTL_PERIPH_UART5))
    {

    }
    /* Initialize the UART. Set the baud rate, number of data bits, turn off
     parity, number of stop bits, and stick mode. The UART is enabled by the function call */

    UARTConfigSetExpClk(UART5_BASE, SysCtlClockGet(), 9600,(UART_CONFIG_WLEN_8 | UART_CONFIG_STOP_ONE |UART_CONFIG_PAR_NONE));

}

/************************************************************************/
/* FUNCTION NAME: UART_RecieveChar                                      */
/* @Param: void                                                         */
/* return: receive the data                                             */
/* FUNCTION Description: Receive data                                   */
/************************************************************************/
uint8_t UART5_RecieveChar(void)
{
    uint8_t data = ZeroAscii;

    /* check if a character is received */
    if(UARTCharsAvail(UART5_BASE))
    {
        /* Reciever data */
        data = UARTCharGetNonBlocking(UART5_BASE);


    }
    return data;
}
