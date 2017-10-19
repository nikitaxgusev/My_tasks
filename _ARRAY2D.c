#include <stdio.h>
#include <stdlib.h>
#include "_ARRAY2D.h"


//The task is from http://oop.afti.ru/task_blocks/1-razgon
//Need to release ARRAY 2D with functions: create 2D array
// which is base on struct,free() array, set an element, get an element
//fill an array

//19.10.2017 12:55


int main()
{
    struct _Array2D* arr=Array_create(2,4);
    Array_fill(arr,2);
    int a=array_get(arr,0,1);
    printf("ARG, : %d\n",a);
    array_set(arr,0,1,3);
    Array_delete(arr);

    return 0;
}


