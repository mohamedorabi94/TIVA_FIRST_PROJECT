/*
 * Timer.c
 *
 * Created: 2/14/2019 3:44:00 PM
 *  Author: AVE-LAP-032
 */ 

#include "Timer.h"



#define RED_LED   GPIO_PIN_1
#define BLUE_LED  GPIO_PIN_2
#define GREEN_LED GPIO_PIN_3

/*Pointer to Function used for calling the Set_Flag Function*/
volatile void (*Call_Back) (void) ;


/**************************************************************************************/
/* NAME:      Set_Call_Back                                                           */
/*DESCRIPTION:Initializes The call back function to be called in Handler Every OS_TICK*/
/**************************************************************************************/
void Set_Call_Back( volatile void (*Ptr) (void) )
{
	Call_Back = Ptr ;
}


/**********************************************************************************/
/* NAME:      Timer_init_INT()                                                    */
/*DESCRIPTION:Function to initialize Systick_Timer  interrupt                     */
/**********************************************************************************/
void Timer_init_INT()
{
         SysTickEnable();
         SysTickPeriodSet(16000-1);
         SysTickIntEnable();
         IntMasterEnable();
}

/************************************************************************/
/*NAME:        SysTick_Handler()                                        */
/*DESCRIPTION:INTERRUPT Function That call the Set_Flag Function        */
/************************************************************************/
SysTick_Handler()
{
    Call_Back(); /*Call The Callback Function Which Is Set_flag Using Pointer to Function*/
}
