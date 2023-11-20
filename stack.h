#ifndef STACK
#define STACK

#include <stdlib.h>

typedef int elem_t; //when we want to change int to float/double/char and so on

struct Stack{
    size_t stack_size;
    size_t capacity;
    elem_t* data;
};


enum ERRORS{
    OK              = 0 << 0, // << pushes number to particular quantity of bytes
    NO_MEMORY       = 1 << 1,
    EMPTY_STACK     = 1 << 2,
    STACK_NULL      = 1 << 3,
    STACK_DATA_NULL = 1 << 4,

};

enum ERRORS Stack_ctor(struct Stack* stk);
enum ERRORS Stack_dtor(struct Stack* stk);
enum ERRORS Stack_pop(struct Stack* stk, elem_t* top);
enum ERRORS Stack_push(struct Stack* stk, elem_t inserted_value);

#endif
