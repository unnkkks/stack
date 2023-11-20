#include "stack.h"
#include <stdio.h>

int main()
{
    struct Stack stk = {0};
    Stack_ctor(&stk);
    printf("Enter the quantity of numbers you want to push\n");
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        elem_t input;
        scanf("%d", &input);
        Stack_push(&stk, input);
    }
    printf("Your stack:");
}
