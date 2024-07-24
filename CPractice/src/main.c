#include<stdio.h>
#include"..\implementations\vector_type.h"
#include"..\implementations\string_type.h"

#pragma warning(disable : 4996)

int main(void)
{
    t_string* str = append("sadasdaA");


    str = string_insert(str, 3, 's');
  
    free(str);

    return 1;
}