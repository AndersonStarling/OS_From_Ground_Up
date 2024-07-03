#ifndef OS_SCHEDULER_H
#define OS_SCHEDULER_H

#define OS_MAX_TASK 3u
#define OS_TASK_STACK_SIZE 0x1000u

extern uint32_t Task_1_Stack_Start_Address;
extern uint32_t Task_2_Stack_Start_Address;
extern uint32_t Task_3_Stack_Start_Address;

typedef struct
{
    volatile uint32_t * Bottom_Of_Stack;
    volatile uint32_t * Top_Of_Stack;
    volatile uint32_t * Current_Stack_Pointer;
    uint32_t          * Task_Function_Handler;
    uint32_t            Task_Stack_Size;
} OS_Task_Struct_t;

typedef struct
{
    uint32_t Task_Running_Index;
    OS_Task_Struct_t * OS_Task_Pointer;
} OS_Scheduler_struct_t;




#endif /* OS_SCHEDULER_H */



