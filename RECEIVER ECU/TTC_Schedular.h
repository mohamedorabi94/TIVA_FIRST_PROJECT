/*
 * TTC_Schedular.h
 *
 * Created: 2/23/2019 4:35:25 PM
 *  Author: AVE-LAP-032
 */ 


#ifndef TTC_SCHEDULAR_H_
#define TTC_SCHEDULAR_H_

#include <stdint.h>
#include "Timer.h"
#include "Tasks/Tasks.h"
#include <stdbool.h>
#include "inc/hw_types.h"
#include "inc/hw_memmap.h"
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"
#include "driverlib/systick.h"
#include "driverlib/interrupt.h"

extern volatile uint8_t  NewTickFlag;

#define FALSE 0

#define TRUE  1

uint8_t Tasks_Index;

typedef struct
{
	void (*pointer) (void);
	uint16_t Periodicity;
	uint16_t Remain;
	uint16_t Priority;
}Task;

#define ZERO 0
#define ONE  1

/* Task_Priorites */
#define FIRST_PRIORITY   1
#define SECOND_PRIORITY  2
#define THIRD_PRIORITY   3
#define FOURTH_PRIORITY  4

/* Task_Periods */
#define ONE_SECONDS    1000
#define TWO_SECONDS    2000
#define THREE_SECONDS  3000
#define FOUR_SECONDS   4000

#define ONE_OS_TICK    1

extern volatile Task Task_arr[MAX_NO_OF_TASKS];

void Swap_Tasks(Task * Task1_ptr,Task * Task2_ptr);

void Sort_Tasks();

void Simple_Schedular();

volatile void Set_flag(void);

uint8_t scheduler_Add_Task (Task * ptr);

void OS_scheduler_Init (void);

void OS_scheduler_Start (void);

void scheduler_Remove_Task (void);



#endif /* TTC_SCHEDULAR_H_ */
