#include "stack.h"
#include <stdlib.h>
#include <assert.h>

const size_t stack_multiplier = 2;
const size_t stack_start_capacity = 10;

enum ERRORS Stack_ctor(struct Stack* stk)
{
    assert(stk);
    
    stk->data = (elem_t*) calloc(stack_start_capacity, sizeof(elem_t));
    assert(stk->data);
    stk->stack_size = 0;
    stk->capacity = stack_start_capacity;
    return OK;
}

enum ERRORS Stack_dtor(struct Stack* stk)
{
    assert(stk);
    
    free(stk->data);
    stk->data = NULL;
    stk->stack_size = 0;
    stk->capacity = 0;
    return OK;
}

enum ERRORS Stack_push(struct Stack* stk, elem_t inserted_value)
{
    assert(stk);
    
    if (stk->stack_size == stk->capacity)
    {
        stk->capacity *= stack_multiplier;
        stk->data = (elem_t*) realloc(stk->data, stk->capacity*sizeof(elem_t));
        assert(stk->data);
    }
    stk->data[stk->stack_size] = inserted_value;
    stk->stack_size++;
    return OK;
}

enum ERRORS Stack_pop(struct Stack* stk, elem_t* top)
{
    assert(stk);
    
    if (stk->stack_size == 0)
    {
        return EMPTY_STACK;
    }

    stk->stack_size--;
    if (top)
        *top = stk->data[stk->stack_size];

    stk->data[stk->stack_size] = 0;
    return OK;
}
