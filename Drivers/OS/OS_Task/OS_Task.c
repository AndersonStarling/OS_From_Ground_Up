#include <stdint.h>
#include "OS_Task.h"

typedef struct
{
    uint32_t task_1;
    uint32_t task_2;
    uint32_t task_3;
} task_struct_t;

volatile task_struct_t task_variable = 
{
    .task_1 = 0,
    .task_2 = 0,
    .task_3 = 0
};

void Task_1(void)
{
    for(;;)
    {
        task_variable.task_1 ++;
    }
}

void Task_2(void)
{
    for(;;)
    {
        task_variable.task_2 ++;
    }
}

void Task_3(void)
{
    for(;;)
    {
        task_variable.task_3 ++;
    }
}



