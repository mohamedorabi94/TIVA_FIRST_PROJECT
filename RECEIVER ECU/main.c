


#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_types.h"
#include "inc/hw_memmap.h"
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"
#include "driverlib/systick.h"
#include "driverlib/interrupt.h"

#include "TTC_Schedular.h"
#include "Tasks/Tasks.h"





void main ()
{

    UART5_INIT();/*intialize Uart*/


     Task task1,task2;/*creat struct*/


     task1.pointer=LCD_INIT;/*struct for task one*/
     task1.Periodicity=NUM_1;
     task1.Remain=NUM_1;
     task1.Priority=FIRST_PRIORITY;

     task2.pointer=KTR;/*struct for task two*/
     task2.Periodicity=NUM_30;
     task2.Remain=NUM_30;
     task2.Priority=SECOND_PRIORITY;



   scheduler_Add_Task(&task1);/*add tasks to schedular*/

   scheduler_Add_Task(&task2);



   OS_scheduler_Init ();/*initialize scheduler*/

   OS_scheduler_Start();/*start scheduler*/

}


