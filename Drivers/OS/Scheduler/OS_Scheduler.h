#ifndef OS_SCHEDULER_H
#define OS_SCHEDULER_H

#define XSPR_INDEX 15u
#define PC_INDEX   14u
#define LR_INDEX   13u
#define R12_INDEX  12u
#define R3_INDEX   11u
#define R2_INDEX   10u
#define R1_INDEX    9u
#define R0_INDEX    8u
#define R11_INDEX   7u
#define R10_INDEX   6u
#define R9_INDEX    5u
#define R8_INDEX    4u
#define R7_INDEX    3u
#define R6_INDEX    2u
#define R5_INDEX    1u
#define R4_INDEX    0u

extern uint32_t Task_1_Stack_Start_Address;
extern uint32_t Task_2_Stack_Start_Address;
extern uint32_t Task_3_Stack_Start_Address;

typedef struct
{
    OS_Task_Struct_t * OS_Task_Pointer;
    uint32_t         Task_Running_Index;
    OS_Task_Struct_t OS_List_Task_Ready[OS_MAX_TASK];
} OS_Scheduler_struct_t;




#endif /* OS_SCHEDULER_H */



