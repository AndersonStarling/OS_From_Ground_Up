#include <stdint.h>
#include "OS_Scheduler.h"
#include "OS_Task_Function_Handler.h"
#include "OS_Task_Information.h"

OS_Task_Struct_t OS_Task[OS_MAX_TASK] =
{
    [0] = 
    {
        .Bottom_Of_Stack = &Task_1_Stack_Start_Address,
        .Top_Of_Stack    = &Task_1_Stack_Start_Address + OS_TASK_STACK_SIZE,
        .Task_Function_Handler = OS_Task_1_Handler
    },

    [1] = 
    {
        .Bottom_Of_Stack = &Task_2_Stack_Start_Address,
        .Top_Of_Stack    = &Task_2_Stack_Start_Address + OS_TASK_STACK_SIZE,
        .Task_Function_Handler = OS_Task_2_Handler
    },

    [2] = 
    {
        .Bottom_Of_Stack = &Task_3_Stack_Start_Address,
        .Top_Of_Stack    = &Task_3_Stack_Start_Address + OS_TASK_STACK_SIZE,
        .Task_Function_Handler = OS_Task_3_Handler
    }
};















