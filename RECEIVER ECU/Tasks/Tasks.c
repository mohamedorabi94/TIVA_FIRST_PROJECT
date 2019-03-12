/*
 * Tasks.c
 *
 * Created: 2/23/2019 3:28:42 PM
 *  Author: AVE-LAP-032
 */ 
#include "Tasks/Tasks.h"
#include "driverlib/sysctl.h"




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

void LCD_INIT()
{

    //
    // Enable the GPIO port that is used for the on-board LED.
    //
    if(i==ZERO){
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);
    //
    // Check if the peripheral access is enabled.
    //
    while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOA))
    {
    }
    //
      // Enable the GPIO port that is used for the on-board LED.
      //
      SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOC);
      //
      // Check if the peripheral access is enabled.
      //
      while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOC))
      {
      }
    //
    // Enable the GPIO pin for the LED (PF3).  Set the direction as output, and
    // enable the GPIO pin for digital function.
    //
    GPIOPinTypeGPIOOutput(PORT1_LCD,LCD_RS|LCD_RW|LCD_E);
    GPIOPinTypeGPIOOutput(PORT2_LCD,LCD_D4|LCD_D5|LCD_D6|LCD_D7);

    }
switch(i){
case ZERO:
         LCD_Send_Command (CMND1_4BITMODE);/*SEND COMMANDS*/
         break;
    case ONE:
         LCD_Send_Command (CMND2_4BITMODE);
         break;
    case TWO:
         LCD_Send_Command (CMND3_4BITMODE);
         break;
    case THREE:
        LCD_Send_Command (CURSOR_ON);
         break;
    case FOUR:
         LCD_Send_Command (CLEAR_LCD);
         break;
       default :
           break;
}

}

/*************************LCD_sendCommand()*********************
*Parameters :
*           I/P:
*           O/P:
*           I/P:
*Return:
*Description: SEND COMMAND TO KCD
********************************************************/


void KTR(void)
{ uint8_t  X=ZERO;

    X=UART5_RecieveChar();/*CHECK DATARECIEVED*/
    if(X != '0')
    {

        LCD_Send_Data (X);/*PRINT Character on lcd*/

    }


}
