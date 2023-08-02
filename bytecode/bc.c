#include "tokens.h"
#include "../stack/vm-stack.h"

#include "bc.h"

int ip;

int debug_vm_exc()
{
    int bcode [16] = {
        EXC,
        PUSH,
        124421,
    };
    return execute_bytecode(bcode);
}

int execute_bytecode(int* b_code)
{
    ip = 0;
    if (!b_code)
    {
        return 1; // error
    }
    else
    {
        switch (b_code[ip])
        {
        case EXC:
            allocate_stack(512);
            ip++;
            break;
        case PUSH:
            ip++;
            push(b_code[ip]);
            ip++;
            break;
        case SUM:
            ip++;
            sum();
        case SUB:
            ip++;
            sub();
        case MUL:
            ip++;
            mul();
        case DIV:
            ip++;
            div();
        default:
            return 1; // error caused by unknown token
            break;
        }
        return 0;
    }
}