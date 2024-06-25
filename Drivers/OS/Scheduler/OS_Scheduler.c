#include <stdint.h>
#include "OS_Scheduler.h"
#include "OS_Task_API.h"
#include "System_Timer.h"
#include "OS_Task_Information.h"

/* Scheduler data */
OS_Scheduler_struct_t Scheduler = 
{
    .Task_Running_Index = 0;
};

static uint32_t Scheduler_Get_Current_PSP(void)
{
    return Task_Stack_Ptr_Table[Task_Stack_Index];
}

static void Scheduler_Save_Current_PSP(uint32_t Current_PSP)
{
    Task_Stack_Ptr_Table[Task_Stack_Index] = Current_PSP;
}

/* TO DO: implement Scheduler_Init */
void Scheduler_Init()

void Scheduler_Start_OS(void)
{
    /* Init OS task */
    OS_Init_Multiple_Task(void);

    /* Init and start system timer */
    System_Timer_Init();
    System_Timer_Start();

    /* Set PSP */
    __asm volatile("bl Scheduler_Get_Current_PSP");
    __asm volatile("MSR PSP, R0");

    /* Use PSP */
    __asm volatile("MRS R0, CONTROL");
    __asm volatile("ORR R0, R0, #2"); // set bit[1] SPSEL
    __asm volatile("MSR CONTROL, R0");

    /* Call first task */
    ((void (*)())(((uint32_t *)(Task_Stack_Ptr_Table[0]))[PC_INDEX]))();

}

__attribute__ ((naked)) void SysTick_Handler(void)
{
    __asm volatile("PUSH {LR}");

    Systick_Counter ++;

    /* Save PSP */
    __asm volatile("MRS R0, PSP");
    __asm volatile("STMDB R0!, {R4-R11}");

    /* Store PSP because R0 is input param */
    __asm volatile("bl Scheduler_Save_Current_PSP");

    Task_Stack_Index ++;
    Task_Stack_Index = Task_Stack_Index % MAX_OS_TASK;

    __asm volatile("bl Scheduler_Get_Current_PSP");
    __asm volatile("LDMIA R0!, {R4-R11}");
    __asm volatile("MSR PSP, R0");

    __asm volatile("POP {LR}");
    __asm volatile("BX LR");
    
}


