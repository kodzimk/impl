#include<stdio.h>
#include"..\implementations\STL\queue_type.h"

#pragma warning(disable : 4996)

int main(void)
{
    queue* q = queue_create(2);
    q = push(q, 2);
    q = push(q, 3);
    q = push(q, 4);

   while(!empty(q))
   {
       printf("%d\n", front(q));
       q = pop(q);
    }

    free_queue(q);

    return 1;   
}