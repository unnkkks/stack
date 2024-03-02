#ifndef STACK
#define STACK

#include <stdlib.h>

typedef int elem_t; //when we want to change int to float/double/char and so on
typedef int canary_t;

struct Stack{
    canary_t left_canary;
    size_t size;
    size_t capacity;
    elem_t* data;
    canary_t right_canary;
};

static const size_t stack_multiplier = 2;
static const size_t stack_start_capacity = 10;
static const unsigned long stack_poison = 0xAB0BA;
static const canary_t STACK_LEFT_CANARY = 0xBEBEBE;
static const canary_t STACK_RIGHT_CANARY = 0xBEBEBE;
static const canary_t DATA_LEFT_CANARY = 0xDEDDED;
static const canary_t DATA_RIGHT_CANARY = 0xDEDDED;

enum ERRORS{
    OK              = 0 << 0, // << pushes number to particular quantity of bytes
    NO_MEMORY       = 1 << 1,
    EMPTY_STACK     = 1 << 2,
    STACK_NULL      = 1 << 3,
    STACK_DATA_NULL = 1 << 4,

};

enum ERRORS stack_ctor(struct Stack* stk, size_t capacity = stack_start_capacity);
enum ERRORS stack_dtor(struct Stack* stk);
enum ERRORS stack_pop(struct Stack* stk, elem_t* top);
enum ERRORS stack_push(struct Stack* stk, elem_t inserted_value);
enum ERRORS stack_resize_up(struct Stack* stk, size_t stack_start_capacity, size_t stack_multiplier);
enum ERRORS stack_resize_down(struct Stack* stk);
enum ERRORS stack_verification(struct Stack* stk);
enum ERRORS stack_dump(struct Stack* stk);

size_t maximum(size_t num_1, size_t num_2);

#endif
