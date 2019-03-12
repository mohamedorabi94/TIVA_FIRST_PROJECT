/*
 * LCD.C
 *
 *  Created on: Mar 12, 2019
 *      Author: AVE-LAP-063
 */
#include"LCD_FILE/LCD.h"
#include"LCD_FILE/Magic_Num.h"
     uint8_t j=ZERO;
     uint8_t i=ZERO;
     uint8_t h=ZERO;


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


/*************************LCD_sendCommand()*********************
*Parameters :
*           I/P:
*           O/P:
*           I/P:
*Return:
*Description: SEND COMMAND TO KCD
****************************************************************/
void LCD_Send_Command (uint8_t cmd){


    switch (j){
    case ZERO :
        GPIOPinWrite(PORT2_LCD, LCD_D4,Get_Bit(cmd,FOUR) );
        GPIOPinWrite(PORT2_LCD, LCD_D5,Get_Bit(cmd,FIVE) );
        GPIOPinWrite(PORT2_LCD, LCD_D6,Get_Bit(cmd,SIX) );
        GPIOPinWrite(PORT2_LCD, LCD_D7,Get_Bit(cmd,SEVEN));
        GPIOPinWrite(PORT1_LCD, LCD_RS,ZERO);
        GPIOPinWrite(PORT1_LCD, LCD_RW,ZERO);
        GPIOPinWrite(PORT1_LCD, LCD_E,LCD_E);
        j=ONE;
        break ;
    case ONE :
        GPIOPinWrite(PORT1_LCD, LCD_E,ZERO);
        j=TWO;
        break;
    case TWO :
             GPIOPinWrite(PORT2_LCD, LCD_D4,((Get_Bit(cmd,ZERO))<<FOUR) );
             GPIOPinWrite(PORT2_LCD, LCD_D5,((Get_Bit(cmd,ONE))<<FOUR  ));
             GPIOPinWrite(PORT2_LCD, LCD_D6,((Get_Bit(cmd,TWO)) <<FOUR) );
             GPIOPinWrite(PORT2_LCD, LCD_D7,((Get_Bit(cmd,THREE))<<FOUR) );
             GPIOPinWrite(PORT1_LCD, LCD_E,LCD_E);
           j++;
         break ;
         case THREE :
             GPIOPinWrite(PORT1_LCD, LCD_E,ZERO);
         j=ZERO;
         i++;
             break;
         default :
             break;


    }




}

/*************************LCD_SENDC_DATA()*********************
*Parameters :
*           I/P:DATA
*           O/P:VOID
*           I/P:VOID
*Return: VOID
*Description: DISPLAY CHARAACTER ON LCD
********************************************************/
void LCD_Send_Data (uint8_t DATA){


    switch (h){
    case ZERO:
    GPIOPinWrite(PORT2_LCD, LCD_D4,Get_Bit(DATA,FOUR) );
    GPIOPinWrite(PORT2_LCD, LCD_D5,Get_Bit(DATA,FIVE) );
    GPIOPinWrite(PORT2_LCD, LCD_D6,Get_Bit(DATA,SIX) );
    GPIOPinWrite(PORT2_LCD, LCD_D7,Get_Bit(DATA,SEVEN));
    GPIOPinWrite(PORT1_LCD, LCD_RS,LCD_RS);
    GPIOPinWrite(PORT1_LCD, LCD_RW,0x0);
    GPIOPinWrite(PORT1_LCD, LCD_E,LCD_E);
    h++;
    break;
    case ONE:
    GPIOPinWrite(PORT1_LCD, LCD_E,0x0);
    h++;
    break;
    case TWO:
    GPIOPinWrite(PORT2_LCD, LCD_D4,((Get_Bit(DATA,ZERO))<<FOUR) );
    GPIOPinWrite(PORT2_LCD, LCD_D5,((Get_Bit(DATA,ONE))<<FOUR  ));
    GPIOPinWrite(PORT2_LCD, LCD_D6,((Get_Bit(DATA,TWO)) <<FOUR) );
    GPIOPinWrite(PORT2_LCD, LCD_D7,((Get_Bit(DATA,THREE))<<FOUR) );
    GPIOPinWrite(PORT1_LCD, LCD_E,LCD_E);
    h++;
    break;
    case THREE :
    GPIOPinWrite(PORT1_LCD, LCD_E,ZERO);
    h++;
    break;
    default :
        break;
    }
}

