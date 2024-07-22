#include <stdint.h>
#include <stdbool.h>
#include "OS_Task_Information.h"
#include "OS_Scheduler.h"
#include "OS_Task_API.h"
#include "System_Timer.h"


/* Scheduler data */
OS_Scheduler_struct_t Scheduler = 
{
    .Task_Running_Index = 0,
    .OS_Task_Pointer = &OS_Task[0]
};

static void Scheduler_Init_Ready_List(void)
{
    uint32_t Index = 0;

    for(Index = 0; Index < OS_MAX_TASK; Index ++)
    {
        if(Scheduler.OS_Task_Pointer[Index].Task_Ready == true)
        {
            Scheduler.OS_List_Task_Ready[Index] = Scheduler.OS_Task_Pointer[Index];
        }
    }
}

static uint32_t Scheduler_Get_Current_PSP(void)
{
    return Scheduler.OS_List_Task_Ready[Scheduler.Task_Running_Index].Current_Stack_Pointer;
}

static void Scheduler_Save_Current_PSP(uint32_t Current_PSP)
{
    Scheduler.OS_List_Task_Ready[Scheduler.Task_Running_Index].Current_Stack_Pointer = Current_PSP;
}

void Scheduler_Start_OS(void)
{
    /* Init OS task */
    OS_Init_Multiple_Task();
    Scheduler_Init_Ready_List();

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
    ((void (*)())(((uint32_t *)(Scheduler.OS_List_Task_Ready[0].Current_Stack_Pointer))[PC_INDEX]))();

}

__attribute__ ((naked)) void SysTick_Handler(void)
{
    __asm volatile("PUSH {LR}");

    /* Save PSP */
    __asm volatile("MRS R0, PSP");
    __asm volatile("STMDB R0!, {R4-R11}");

    /* Store PSP because R0 is input param */
    __asm volatile("bl Scheduler_Save_Current_PSP");

    Scheduler.Task_Running_Index ++;
    Scheduler.Task_Running_Index = Scheduler.Task_Running_Index % OS_MAX_TASK;

    __asm volatile("bl Scheduler_Get_Current_PSP");
    __asm volatile("LDMIA R0!, {R4-R11}");
    __asm volatile("MSR PSP, R0");

    __asm volatile("POP {LR}");
    __asm volatile("BX LR");
    
}


