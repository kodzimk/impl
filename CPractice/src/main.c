#include<stdio.h>
#include<stdlib.h>
#include"..\implementations\STL\linked_list.h"


int main(int argv,char** argc)
{
    list_t* list = createV(10);
    addNodeV(list, 4);

    list_t* temp = list;

    while (temp != NULL)
    {
        printf("%d\n",temp->value[0]);
        temp = temp->next;
    }

    free_list(list);
    return 1;
}