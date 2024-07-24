#include<stdio.h>
#include"..\implementations\STL\vector_type.h"
#include"..\implementations\DataType\string_type.h"

#pragma warning(disable : 4996)

int main(void)
{
    t_string* str = append("sadasdaA");


    str = string_insert(str, 3, 's');
  
    free(str);

    return 1;
}