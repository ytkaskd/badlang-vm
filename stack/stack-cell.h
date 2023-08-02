enum TYPE
{
    Bool,
    Int,
    Object,
    Reference,
    Pointer
};

enum TYPE value_type = Int;

union stack_cell
{
    int value;
};