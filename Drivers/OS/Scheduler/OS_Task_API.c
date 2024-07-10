#include <stdint.h>
#include "OS_Scheduler.h"
#include "OS_Task_Function_Handler.h"
#include "OS_Task_Information.h"
#include "OS_Task_API.h"

static void OS_Init_Single_Task(OS_Task_Struct_t * OS_Task)
{
    /* Store XPSR */
    *(OS_Task->Top_Of_Stack) = 0x01000000u;
    OS_Task->Top_Of_Stack --;

    /* Store PC */
    *(OS_Task->Top_Of_Stack) = (uint32_t)OS_Task->Task_Function_Handler;
    OS_Task->Top_Of_Stack --;

    /* Store LR */
    *(OS_Task->Top_Of_Stack) = 0xFFFFFFFDu;
    OS_Task->Top_Of_Stack --;

    /* Store R12 */
    *(OS_Task->Top_Of_Stack) = 0x12121212u;
    OS_Task->Top_Of_Stack --;

    /* Store R3 */
    *(OS_Task->Top_Of_Stack) = 0x03030303u;
    OS_Task->Top_Of_Stack --;

    /* Store R2 */
    *(OS_Task->Top_Of_Stack) = 0x02020202u;
    OS_Task->Top_Of_Stack --;

    /* Store R1 */
    *(OS_Task->Top_Of_Stack) = 0x01010101u;
    OS_Task->Top_Of_Stack --;

    /* Store R0 */
    *(OS_Task->Top_Of_Stack) = 0x00000000u;
    OS_Task->Top_Of_Stack --;

    /* Store R11 */
    *(OS_Task->Top_Of_Stack) = 0x11111111u;
    OS_Task->Top_Of_Stack --;

    /* Store R10 */
    *(OS_Task->Top_Of_Stack) = 0x10101010u;
    OS_Task->Top_Of_Stack --;

    /* Store R9 */
    *(OS_Task->Top_Of_Stack) = 0x09090909u;
    OS_Task->Top_Of_Stack --;

    /* Store R8 */
    *(OS_Task->Top_Of_Stack) = 0x08080808u;
    OS_Task->Top_Of_Stack --;

    /* Store R7 */
    *(OS_Task->Top_Of_Stack) = 0x07070707u;
    OS_Task->Top_Of_Stack --;

    /* Store R6 */
    *(OS_Task->Top_Of_Stack) = 0x06060606u;
    OS_Task->Top_Of_Stack --;

    /* Store R5 */
    *(OS_Task->Top_Of_Stack) = 0x05050505u;
    OS_Task->Top_Of_Stack --;

    /* Store R4 */
    *(OS_Task->Top_Of_Stack) = 0x04040404u;

    /* Store current stack pointer */
    OS_Task->Current_Stack_Pointer = OS_Task->Top_Of_Stack;

    /* Store stack size left */
    OS_Task->Task_Stack_Size = OS_Task->Current_Stack_Pointer - OS_Task->Bottom_Of_Stack;

}

void OS_Init_Multiple_Task(void)
{
    uint32_t Task_Index = 0;

    /* Init all task */
    for(Task_Index = 0; Task_Index < OS_MAX_TASK; Task_Index ++)
    {
        OS_Init_Single_Task(&OS_Task[Task_Index]);
    }

}











