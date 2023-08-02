struct vm_stack;

struct vm_stack stack_struct;

int allocate_stack(int);
void set_stack_reg(void);
void push(int);
int pop(void);

void sum(void);
void sub(void);
void mul(void);
void div(void);
