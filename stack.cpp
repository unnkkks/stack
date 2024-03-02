#include "stack.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

size_t maximum(size_t num_1, size_t num_2)
{
    return num_1 > num_2 ? num_1 : num_2;
}

enum ERRORS stack_ctor(struct Stack* stk, size_t capacity)
{
    assert(stk);
    
    stk->left_canary = STACK_LEFT_CANARY;
    stk->data = (elem_t*) calloc(maximum(stack_start_capacity, capacity), sizeof(elem_t));
    if (!stk->data) return STACK_DATA_NULL;
    stk->size = 0;
    stk->capacity = maximum(stack_start_capacity, capacity);
    stk->right_canary = STACK_RIGHT_CANARY;
    return OK;
}

enum ERRORS stack_dtor(struct Stack* stk)
{
    assert(stk);
    
    for (int index = 0; index < stk->capacity; index++)
    {
        stk->data[i] = stack_poison;
    }

    free(stk->data);
    stk->data = NULL;
    stk->size = 0;
    stk->capacity = 0;
    return OK;
}

enum ERRORS stack_push(struct Stack* stk, elem_t inserted_value)
{
    assert(stk);
    stk->data[stk->size] = inserted_value;
    stk->size++;
    return OK;
}

enum ERRORS stack_resize_up(struct Stack* stk, size_t stack_start_capacity, size_t stack_multiplier)
{
     if (stk->size == stk->capacity)
    {   
        stk->capacity *= stack_multiplier;
        elem_t* save_data = stk->data; 
        stk->data = (elem_t*) realloc(stk->data, stk->capacity*sizeof(elem_t));
        if (stk->data == NULL)
        {
            stk->data = save_data;
            return NO_MEMORY;
        }
    }
    return OK;    
}

enum ERRORS stack_resize_down(struct Stack* stk)
{
    if (stk->capacity > 3*stk->size)
    {
        stk->data = (elem_t*) realloc(stk->data, (stk->capacity-((stk->capacity - stk->size)/2))*sizeof(elem_t));
    }
    return OK;
}

enum ERRORS stack_pop(struct Stack* stk, elem_t* top)
{
    assert(stk);
    
    if (stk->size == 0) return EMPTY_STACK;

    stk->size--;
    if (top)
        *top = stk->data[stk->size];

    stk->data[stk->size] = 0;
    return OK;
}

enum ERRORS stack_verification(struct Stack* stk)
{
    if (stk->capacity > stk->size) return OK;
    else return NO_MEMORY;
    if (stk->data != NULL) return OK;
    else return STACK_DATA_NULL;

}

enum ERRORS stack_dump(struct Stack* stk)
{
    printf("------------------------------\n");
    printf("Information about your stack:\n");
    printf("Current size of stack: %ld\n", stk->size);
    printf("Current capacity of stack: %ld\n", stk->capacity);
    printf("Current data of stack:\n");
    for (int index = 0; index < stk->size; index++)
    {
        if (index != stk->size-1)
        {
            printf("%d, ",stk->data[i]);
        }
        if (index == stk->size-1)
        {
            printf("%d \n", stk->data[i]);
        }
    }
    printf("------------------------------\n");
    return OK;
}

//realloc down +-
// write verification +-
//dump +-
//poison +-
//канарейки в структуре и в данных