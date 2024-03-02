#include "stack.h"
#include <stdio.h>

int main()
{
    struct Stack stk = {0};
    stack_ctor(&stk);
    printf("Enter the quantity of numbers you want to push\n");
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        elem_t input;
        printf("Please enter the numbers you want to push\n");
        scanf("%d", &input);
        stack_push(&stk, input);
    }
    stack_dump(&stk);
    stack_dtor(&stk);
}