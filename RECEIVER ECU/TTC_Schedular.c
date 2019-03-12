/*
 * TTC_Schedular.c
 *
 * Created: 2/23/2019 4:35:43 PM
 *  Author: AVE-LAP-032
 */ 
#include "TTC_Schedular.h"


volatile uint8_t  NewTickFlag = ZERO;

volatile Task Task_arr[MAX_NO_OF_TASKS];

volatile uint8_t No_Of_Tasks = ZERO;

/************************************************************************/
/*  NAME:                  Simple_Schedular ()                          */
/*  DESCRIPTION:Handles Executing Tasks one by one                      */
/************************************************************************/

void Simple_Schedular ()
{
    uint32_t Sindex;  /*Index to loop over the tasks*/
	
	for(Sindex=0;Sindex<No_Of_Tasks;Sindex++)
	{
		Task_arr[Sindex].Remain--;             /*Index to loop over the tasks*/
		if(Task_arr[Sindex].Remain==ZERO)          
		{
			Task_arr[Sindex].pointer();        /*Call the task */
			Task_arr[Sindex].Remain=Task_arr[Sindex].Periodicity; /*Reset the remaining ticks to the initial value*/
		}
	}
}

/************************************************************************/
/*  NAME:  scheduler_Add_Task                                           */            
/*  DESCRIPTION:Handles Executing Tasks one by one                      */
/************************************************************************/
uint8_t scheduler_Add_Task (Task * Ptr_To_New_Task)
{
	uint8_t Result;
	
	if ( No_Of_Tasks < MAX_NO_OF_TASKS )
	{
		Task_arr[No_Of_Tasks]= *Ptr_To_New_Task;
		No_Of_Tasks ++ ;
		Result=TRUE;
	}
	
	else Result=FALSE;
	
	return Result;
	
}

/************************************************************************/
/* NAME: Sort_Tasks()                                                   */
/* DESCRIPTION: Sorts All The Tasks                                    */
/************************************************************************/

void Sort_Tasks()
{ 
	uint8_t Sort_Index1,Sort_Index2; /* Index For First And Second Loops */
	Task Temp; /*Temp Task Used for swapping */
	for (Sort_Index1=ZERO; Sort_Index1<No_Of_Tasks-ONE; Sort_Index1++)
	{
		for (Sort_Index2=Sort_Index1+ONE; Sort_Index2<No_Of_Tasks; Sort_Index2++)
		{
			/*swap if priority of the leading task in the array of tasks is lower than the following */
			if (Task_arr[Sort_Index1].Priority > Task_arr[Sort_Index2].Priority)
			{
				Temp= Task_arr[Sort_Index1];
				Task_arr[Sort_Index1]=Task_arr[Sort_Index2];
				Task_arr[Sort_Index2]=Temp;				
			}
		}
		
	}
}

/************************************************************************/
/* NAME: scheduler_Remove_Task ()                                       */
/* DESCRIPTION: Removes Tasks In Case of Event                          */
/************************************************************************/
void scheduler_Remove_Task ()
{
	uint8_t Task_arr_Index ;
	
	/*Shift Tasks To Remove Tasks from the beginning of the array(Queue) */
	for (Task_arr_Index=ZERO; Task_arr_Index < No_Of_Tasks-ONE; Task_arr_Index++)
	{
		Task_arr[Task_arr_Index] = Task_arr[Task_arr_Index+ONE] ;	
	}
	/*Decrease number of Tasks after removing */
	No_Of_Tasks--;
}

/************************************************************************/
/* NAME: OS_scheduler_Init ()                                           */
/* DESCRIPTION: Removes Tasks In Case of Event                          */
/************************************************************************/

void OS_scheduler_Init ()
{
	/* Sort Tasks according to priority*/
	 Sort_Tasks();
	/*Initialize the call_back pointer to function to Set_flag function */ 
    Set_Call_Back(Set_flag);			
}


/****************************************************************************/
/* NAME: OS_scheduler_Start()                                               */
/* DESCRIPTION: Initializes the timer and Handles Executing the tasks       */
/****************************************************************************/
 void OS_scheduler_Start()
{
	/*Start The Timer*/
	Timer_init_INT();
	
	/*Loop To handle all Tasks Every Tick*/
	while(HIGH)
	{
	/*If flag is True reset it and handle the next task*/
		if(NewTickFlag == TRUE)
		{
			NewTickFlag = FALSE ;
			Simple_Schedular();
		}
	}
	
}


/**************************************************************************************/
/* NAME: Set_flag()                                                                   */
/* DESCRIPTION: Used by the callback to set the flag to true to indicate a new OS_tick*/
/**************************************************************************************/
volatile void Set_flag()
{
	NewTickFlag=TRUE;
}





