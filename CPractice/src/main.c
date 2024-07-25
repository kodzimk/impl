#include<stdio.h>
#include"..\implementations\STL\stack_type.h"

#pragma warning(disable : 4996)

int main(void)
{
    stack* q = stack_create(2);
    q = push(q, 2);
    q = push(q, 3);
    q = push(q, 4);


    while (!empty(q))
    {
        printf("%d\n", top(q));
        q = pop(q);
     }

    

    free_stack(q);

    return 1;   
}