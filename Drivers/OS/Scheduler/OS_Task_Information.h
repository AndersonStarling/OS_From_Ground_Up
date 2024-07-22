#ifndef OS_TASK_INFORMATION_H
#define OS_TASK_INFORMATION_H

#define OS_MAX_TASK 3u
#define OS_TASK_STACK_SIZE 0x1000u

typedef struct
{
    volatile uint32_t * Bottom_Of_Stack;
    volatile uint32_t * Top_Of_Stack;
    volatile uint32_t * Current_Stack_Pointer;
    uint32_t          * Task_Function_Handler;
    uint32_t            Task_Stack_Size;
    uint8_t             Task_Priority;
    bool                Task_Ready;
} OS_Task_Struct_t;

extern OS_Task_Struct_t OS_Task[OS_MAX_TASK];


#endif /* OS_TASK_INFORMATION_H */






