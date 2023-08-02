#include "stack-cell.h"
#include "vm-stack.h"

#include <stdio.h>
#include <stdlib.h>

struct vm_stack
{
    union stack_cell* sp;
    union stack_cell* bp;
    union stack_cell* stack;
};

struct vm_stack stack_struct;

int allocate_stack(int stack_size)
{
    if (stack_size <= 0)
    {
        stack_struct.stack = (union stack_cell*)calloc(stack_size, sizeof(union stack_cell));
        if (!stack_struct.stack)
        {
            return 1;
        }
        else
        {
            set_stack_reg();
            return 0;
        }
    }
    else
    {
        return 1;
    }
}

void set_stack_reg()
{
    stack_struct.bp = stack_struct.stack;
    stack_struct.sp = stack_struct.stack;
}

void push(int value)
{
    stack_struct.sp--;
    printf("value: %d", value);
    stack_struct.sp[0].value = value;

    printf("stack sp value: %d", stack_struct.sp[0].value);
}

int pop()
{
    stack_struct.sp++;
    return stack_struct.sp[-1].value;
}

void sum()
{
    int a = stack_struct.sp + 1;
    int b = stack_struct.sp + 2;
    push(a + b);
}

void sub()
{
    int a = stack_struct.sp + 1;
    int b = stack_struct.sp + 2;
    push(a - b);
}

void mul()
{
    int a = stack_struct.sp + 1;
    int b = stack_struct.sp + 2;
    push(a * b);
}

void div()
{
    int a = stack_struct.sp + 1;
    int b = stack_struct.sp + 2;
    if (b != 0)
    {
        push(a / b);
    }
    else
    {
        push(0xBADC0DE);
    }
}