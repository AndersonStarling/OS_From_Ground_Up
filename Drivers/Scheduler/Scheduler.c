#include <stdint.h>
#include "System_Timer.h"
#include "Scheduler.h"
#include "OS_Task.h"

#define MAX_OS_TASK 3u
#define LIST_OS_TASK {Task_1, Task_2, Task_3}

#define XSPR_INDEX 16u
#define PC_INDEX   15u
#define LR_INDEX   14u
#define R12_INDEX  13u
#define R3_INDEX   12u
#define R2_INDEX   11u
#define R1_INDEX   10u
#define R0_INDEX    9u
#define R11_INDEX   8u
#define R10_INDEX   7u
#define R9_INDEX    6u
#define R8_INDEX    5u
#define R7_INDEX    4u
#define R6_INDEX    3u
#define R5_INDEX    2u
#define R4_INDEX    1u

#define STACK_SIZE 0x1000u



typedef void (*OS_Task_Table)(void);

extern uint32_t Task_1_Stack_Start_Address;
extern uint32_t Task_2_Stack_Start_Address;
extern uint32_t Task_3_Stack_Start_Address;

uint32_t * Task_1_Stack_Ptr = (&Task_1_Stack_Start_Address + STACK_SIZE);
uint32_t * Task_2_Stack_Ptr = (&Task_2_Stack_Start_Address + STACK_SIZE);
uint32_t * Task_3_Stack_Ptr = (&Task_3_Stack_Start_Address + STACK_SIZE);

uint32_t Task_Stack_Ptr_Table[MAX_OS_TASK] = {0};
uint32_t Task_Stack_Index = 0;

OS_Task_Table My_OS_Task[MAX_OS_TASK] = LIST_OS_TASK;

volatile uint32_t Systick_Counter = 0;

 
static void Scheduler_Init_Task(void * Task_Function_Ptr, uint32_t * Task_Stack_Ptr, uint32_t Task_Stack_Index)
{

    /* Store XPSR */
    *(volatile uint32_t *)Task_Stack_Ptr = 0x01000000u;
    Task_Stack_Ptr --;

    /* Store PC */
    *(volatile uint32_t *)Task_Stack_Ptr = (uint32_t)Task_Function_Ptr;
    Task_Stack_Ptr --;

    /* Store LR */
    *(volatile uint32_t *)Task_Stack_Ptr = 0xFFFFFFFDu;
    Task_Stack_Ptr --;

    /* Store R12 */
    *(volatile uint32_t *)Task_Stack_Ptr = 0x12121212u;
    Task_Stack_Ptr --;

    /* Store R3 */
    *(volatile uint32_t *)Task_Stack_Ptr = 0x03030303u;
    Task_Stack_Ptr --;

    /* Store R2 */
    *(volatile uint32_t *)Task_Stack_Ptr = 0x02020202u;
    Task_Stack_Ptr --;

    /* Store R1 */
    *(volatile uint32_t *)Task_Stack_Ptr = 0x01010101u;
    Task_Stack_Ptr --;

    /* Store R0 */
    *(volatile uint32_t *)Task_Stack_Ptr = 0x00000000u;
    Task_Stack_Ptr --;

    /* Store R11 */
    *(volatile uint32_t *)Task_Stack_Ptr = 0x11111111u;
    Task_Stack_Ptr --;

    /* Store R10 */
    *(volatile uint32_t *)Task_Stack_Ptr = 0x10101010u;
    Task_Stack_Ptr --;

    /* Store R9 */
    *(volatile uint32_t *)Task_Stack_Ptr = 0x09090909u;
    Task_Stack_Ptr --;

    /* Store R8 */
    *(volatile uint32_t *)Task_Stack_Ptr = 0x08080808u;
    Task_Stack_Ptr --;

    /* Store R7 */
    *(volatile uint32_t *)Task_Stack_Ptr = 0x07070707u;
    Task_Stack_Ptr --;

    /* Store R6 */
    *(volatile uint32_t *)Task_Stack_Ptr = 0x06060606u;
    Task_Stack_Ptr --;

    /* Store R5 */
    *(volatile uint32_t *)Task_Stack_Ptr = 0x05050505u;
    Task_Stack_Ptr --;

    /* Store R4 */
    *(volatile uint32_t *)Task_Stack_Ptr = 0x04040404u;
    Task_Stack_Ptr --;

    Task_Stack_Ptr_Table[Task_Stack_Index] = (uint32_t)Task_Stack_Ptr;
}

static uint32_t Scheduler_Get_Current_PSP(void)
{
    return Task_Stack_Ptr_Table[Task_Stack_Index];
}

static void Scheduler_Save_Current_PSP(uint32_t Current_PSP)
{
    Task_Stack_Ptr_Table[Task_Stack_Index] = Current_PSP;
}

void Scheduler_Start_OS(void)
{
    /* Init OS task */
    Scheduler_Init_Task(My_OS_Task[0], Task_1_Stack_Ptr, 0);
    Scheduler_Init_Task(My_OS_Task[1], Task_2_Stack_Ptr, 1);
    Scheduler_Init_Task(My_OS_Task[2], Task_3_Stack_Ptr, 2);
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





